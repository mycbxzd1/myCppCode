// ==UserScript==
// @name         Hydro系统题目页面扩展
// @namespace    https://hydro.ac/
// @version      0.0.0
// @description  题面页一键复制 & 题目状态 适用于所有hydro系统,更改匹配域名即可
// @author       mycbxzd
// @match        https://hydro.ac/d/*/p/*
// @match        https://hydro.ac/p/*
// @grant        GM_setClipboard
// @grant        GM_addStyle
// @grant        unsafeWindow
// @require      https://cdn.jsdelivr.net/npm/chart.js@3.9.1/dist/chart.min.js
// @run-at       document-end
// ==/UserScript==

/* ---------- 全局样式 ---------- */
GM_addStyle(`
  :root {
    --hili-primary: #5b8cff;
    --hili-primary-light: #85b5ff;
    --hili-primary-dark: #4676e8;
    --hili-accent: #6c63ff;
    --hili-success: #52c41a;
    --hili-warning: #faad14;
    --hili-error: #ff4d4f;
    --hili-radius: 16px;
    --hili-radius-sm: 12px;
    --hili-shadow: 0 8px 32px rgba(91, 140, 255, 0.15);
    --hili-shadow-hover: 0 12px 48px rgba(91, 140, 255, 0.25);
    --hili-glass-bg: rgba(255, 255, 255, 0.85);
    --hili-glass-border: rgba(255, 255, 255, 0.5);
    --hili-blur: blur(20px);
    --hili-transition: all 0.3s cubic-bezier(0.4, 0, 0.2, 1);
    --hili-font: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, "Helvetica Neue", Arial, sans-serif;
  }

  /* 浮动按钮 */
  .hili-fab {
    position: fixed;
    bottom: 40px;
    left: 20px;
    display: flex;
    flex-direction: column;
    gap: 12px;
    z-index: 1000;
  }

  /* 主按钮样式 */
  .hili-btn {
    position: relative;
    padding: 12px 24px;
    background: linear-gradient(135deg, var(--hili-primary), var(--hili-primary-dark));
    color: #fff !important;
    border: none;
    border-radius: var(--hili-radius-sm);
    font: 600 14px var(--hili-font);
    cursor: pointer;
    box-shadow: var(--hili-shadow);
    transition: var(--hili-transition);
    overflow: hidden;
    white-space: nowrap;
  }

  .hili-btn::before {
    content: '';
    position: absolute;
    top: 0;
    left: -100%;
    width: 100%;
    height: 100%;
    background: linear-gradient(90deg, transparent, rgba(255,255,255,0.3), transparent);
    transition: left 0.5s;
  }

  .hili-btn:hover {
    transform: translateY(-3px) scale(1.05);
    box-shadow: var(--hili-shadow-hover);
  }

  .hili-btn:hover::before {
    left: 100%;
  }

  .hili-btn:active {
    transform: translateY(-1px) scale(1.02);
  }

  /* 浮动按钮图标 */
  .hili-btn-icon {
    display: inline-flex;
    align-items: center;
    gap: 8px;
  }

  .hili-btn-icon::before {
    content: '';
    width: 18px;
    height: 18px;
    background-size: contain;
    filter: brightness(0) invert(1);
  }

  .hili-btn-copy::before {
    background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='none' stroke='currentColor' stroke-width='2'%3E%3Crect x='9' y='9' width='13' height='13' rx='2' ry='2'%3E%3C/rect%3E%3Cpath d='M5 15H4a2 2 0 0 1-2-2V4a2 2 0 0 1 2-2h9a2 2 0 0 1 2 2v1'%3E%3C/path%3E%3C/svg%3E");
  }

  .hili-btn-stats::before {
    background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='none' stroke='currentColor' stroke-width='2'%3E%3Cline x1='12' y1='20' x2='12' y2='10'%3E%3C/line%3E%3Cline x1='18' y1='20' x2='18' y2='4'%3E%3C/line%3E%3Cline x1='6' y1='20' x2='6' y2='16'%3E%3C/line%3E%3C/svg%3E");
  }

  /* Toast 通知 */
  .hili-toast {
    position: fixed;
    top: 32px;
    right: 32px;
    background: var(--hili-glass-bg);
    backdrop-filter: var(--hili-blur);
    border: 1px solid var(--hili-glass-border);
    color: #333;
    padding: 14px 20px;
    border-radius: var(--hili-radius-sm);
    box-shadow: var(--hili-shadow);
    font: 14px var(--hili-font);
    z-index: 100000;
    opacity: 0;
    transform: translateX(100px);
    animation: slideIn 0.3s forwards;
    display: flex;
    align-items: center;
    gap: 10px;
  }

  .hili-toast.success::before {
    content: '✓';
    display: inline-flex;
    align-items: center;
    justify-content: center;
    width: 24px;
    height: 24px;
    background: var(--hili-success);
    color: white;
    border-radius: 50%;
    font-weight: bold;
  }

  .hili-toast.error::before {
    content: '✕';
    display: inline-flex;
    align-items: center;
    justify-content: center;
    width: 24px;
    height: 24px;
    background: var(--hili-error);
    color: white;
    border-radius: 50%;
    font-weight: bold;
  }

  @keyframes slideIn {
    to {
      opacity: 1;
      transform: translateX(0);
    }
  }

  /* 模态框遮罩 */
  .hili-mask {
    position: fixed;
    inset: 0;
    background: rgba(0, 0, 0, 0.6);
    backdrop-filter: blur(8px);
    display: flex;
    align-items: center;
    justify-content: center;
    z-index: 99998;
    opacity: 0;
    animation: fadeIn 0.3s forwards;
  }

  @keyframes fadeIn {
    to { opacity: 1; }
  }

  /* 统计模态框 */
  .hili-modal {
    width: 90%;
    max-width: 900px;
    background: var(--hili-glass-bg);
    backdrop-filter: var(--hili-blur);
    border: 1px solid var(--hili-glass-border);
    border-radius: var(--hili-radius);
    box-shadow: 0 20px 60px rgba(0, 0, 0, 0.3);
    padding: 0;
    transform: scale(0.9);
    opacity: 0;
    animation: modalShow 0.3s forwards;
    overflow: hidden;
  }

  @keyframes modalShow {
    to {
      transform: scale(1);
      opacity: 1;
    }
  }

  /* 模态框头部 */
  .hili-modal-header {
    padding: 24px 32px;
    background: linear-gradient(135deg, var(--hili-primary), var(--hili-primary-dark));
    color: white;
    display: flex;
    justify-content: space-between;
    align-items: center;
  }

  .hili-modal-title {
    font-size: 20px;
    font-weight: 600;
    display: flex;
    align-items: center;
    gap: 10px;
  }

  .hili-modal-title::before {
    content: '📊';
    font-size: 24px;
  }

  /* 关闭按钮 */
  .hili-close-btn {
    background: rgba(255, 255, 255, 0.2);
    border: 1px solid rgba(255, 255, 255, 0.3);
    color: white;
    width: 32px;
    height: 32px;
    border-radius: 50%;
    display: flex;
    align-items: center;
    justify-content: center;
    cursor: pointer;
    transition: var(--hili-transition);
    font-size: 18px;
  }

  .hili-close-btn:hover {
    background: rgba(255, 255, 255, 0.3);
    transform: rotate(90deg);
  }

  /* 模态框内容 */
  .hili-modal-content {
    padding: 32px;
    display: flex;
    gap: 32px;
    align-items: flex-start;
    background: linear-gradient(135deg, #f5f7fa 0%, #c3cfe2 100%);
  }

  /* 图表容器 */
  .hili-chart-container {
    flex: 1;
    background: white;
    border-radius: var(--hili-radius-sm);
    padding: 24px;
    box-shadow: 0 4px 20px rgba(0, 0, 0, 0.08);
    transition: var(--hili-transition);
  }

  .hili-chart-container:hover {
    box-shadow: 0 8px 30px rgba(0, 0, 0, 0.12);
    transform: translateY(-2px);
  }

  .hili-chart-title {
    font-size: 16px;
    font-weight: 600;
    color: #333;
    margin-bottom: 16px;
    padding-bottom: 12px;
    border-bottom: 2px solid #f0f0f0;
  }

  /* 修改圆形图表容器，确保是正圆 */
  .hili-chart-canvas.circular {
    width: 260px !important;
    height: 260px !important;
    margin: 0 auto;
    display: block;
  }

  .hili-chart-canvas {
    width: 100% !important;
    height: 280px !important;
  }

  /* 统计数据卡片 */
  .hili-stats-summary {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(120px, 1fr));
    gap: 16px;
    margin-top: 24px;
    padding-top: 24px;
    border-top: 2px solid #f0f0f0;
  }

  .hili-stat-card {
    text-align: center;
    padding: 12px;
    background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
    border-radius: var(--hili-radius-sm);
    color: white;
    transition: var(--hili-transition);
  }

  .hili-stat-card:hover {
    transform: translateY(-2px);
    box-shadow: 0 4px 12px rgba(102, 126, 234, 0.4);
  }

  .hili-stat-value {
    font-size: 24px;
    font-weight: bold;
    margin-bottom: 4px;
  }

  .hili-stat-label {
    font-size: 12px;
    opacity: 0.9;
  }

  /* 加载动画 */
  .hili-loading {
    display: inline-block;
    width: 20px;
    height: 20px;
    border: 3px solid rgba(255, 255, 255, 0.3);
    border-radius: 50%;
    border-top-color: white;
    animation: spin 1s ease-in-out infinite;
  }

  @keyframes spin {
    to { transform: rotate(360deg); }
  }
`);

/* ---------- 基本常量 ---------- */
const PAGE = (typeof unsafeWindow !== 'undefined') ? unsafeWindow : window;

/* ---------- Toast 通知 ---------- */
function toast(msg, type = 'success') {
  const t = document.createElement('div');
  t.className = `hili-toast ${type}`;
  t.innerHTML = msg;
  document.body.appendChild(t);
  setTimeout(() => {
    t.style.animation = 'slideIn 0.3s reverse';
    setTimeout(() => t.remove(), 300);
  }, 2500);
}

/* ---------- 等待 UiContextNew ---------- */
let ui = null;
(function poll() {
  const raw = PAGE.UiContextNew;
  if (typeof raw !== 'string') return requestAnimationFrame(poll);
  try { ui = JSON.parse(raw); init(); } catch { requestAnimationFrame(poll); }
})();

/* ---------- 初始化浮动按钮 ---------- */
function init() {
  /* 创建浮动按钮容器 */
  const fab = document.createElement('div');
  fab.className = 'hili-fab';
  document.body.appendChild(fab);

  /* 复制按钮 */
  const copyBtn = createBtn('复制题目', 'copy');
  copyBtn.onclick = handleCopy;
  fab.appendChild(copyBtn);

  /* 题目状态按钮 */
  const statBtn = createBtn('查看统计', 'stats');
  statBtn.onclick = handleStats;
  fab.appendChild(statBtn);
}

/* ---------- 工具函数 ---------- */
function createBtn(txt, icon) {
  const b = document.createElement('button');
  b.className = 'hili-btn';
  b.innerHTML = `<span class="hili-btn-icon hili-btn-${icon}">${txt}</span>`;
  return b;
}

function getUi() {
  if (ui) return ui;
  if (typeof PAGE.UiContextNew !== 'string') return null;
  try { return JSON.parse(PAGE.UiContextNew); } catch { return null; }
}

/* ---------- 复制逻辑 ---------- */
function handleCopy() {
  const cur = getUi();
  let md = '';
  if (cur?.pdoc?.content) {
    try { md = JSON.parse(cur.pdoc.content).zh || ''; } catch { /* ignore */ }
  }
  if (!md) md = document.querySelector('.section__body.typo.richmedia')?.innerText.trim() || '';
  if (!md) return toast('复制失败', 'error');

  (navigator.clipboard?.writeText(md) || Promise.reject())
    .then(() => toast('题目已复制到剪贴板'))
    .catch(() => { GM_setClipboard(md, { type:'text/plain' }); toast('题目已复制到剪贴板'); });
}

/* ---------- 绘制统计图 ---------- */
function handleStats() {
  const stats = getUi()?.pdoc?.stats;
  if (!stats) return toast('无权访问统计数据', 'error');
  if (!window.Chart) return toast('Chart.js 未加载', 'error');

  /* 遮罩 */
  const mask = document.createElement('div');
  mask.className = 'hili-mask';
  document.body.appendChild(mask);

  /* 关闭逻辑 */
  const close = () => {
    mask.style.animation = 'fadeIn 0.3s reverse';
    setTimeout(() => {
      document.removeEventListener('keydown', esc);
      mask.remove();
    }, 300);
  };
  const esc = (e) => e.key === 'Escape' && close();
  document.addEventListener('keydown', esc);
  mask.addEventListener('click', (e) => { if (e.target === mask) close(); });

  /* 模态框 */
  const modal = document.createElement('div');
  modal.className = 'hili-modal';
  mask.appendChild(modal);

  /* 头部 */
  const header = document.createElement('div');
  header.className = 'hili-modal-header';
  header.innerHTML = `
    <div class="hili-modal-title">题目统计分析</div>
    <div class="hili-close-btn">×</div>
  `;
  modal.appendChild(header);
  header.querySelector('.hili-close-btn').onclick = close;

  /* 内容区 */
  const content = document.createElement('div');
  content.className = 'hili-modal-content';
  modal.appendChild(content);

  /* 状态分布图容器 */
  const statusContainer = document.createElement('div');
  statusContainer.className = 'hili-chart-container';
  statusContainer.innerHTML = `
    <div class="hili-chart-title">提交状态分布</div>
    <canvas class="hili-chart-canvas circular" id="statusChart"></canvas>
  `;
  content.appendChild(statusContainer);

  /* 分数分布图容器 */
  const scoreContainer = document.createElement('div');
  scoreContainer.className = 'hili-chart-container';
  scoreContainer.innerHTML = `
    <div class="hili-chart-title">得分分布趋势</div>
    <canvas class="hili-chart-canvas" id="scoreChart"></canvas>
  `;
  content.appendChild(scoreContainer);

  /* 数据准备 */
  const COLOR = {
    AC: '#52c41a',
    WA: '#ff4d4f',
    TLE: '#faad14',
    MLE: '#fa8c16',
    RE: '#13c2c2',
    SE: '#722ed1',
    IGN: '#8c8c8c',
    CE: '#eb2f96',
  };

  const statusKeys = ['AC', 'WA', 'TLE', 'MLE', 'RE', 'SE', 'IGN', 'CE'].filter(k => stats[k] > 0);

  /* 动态解析所有 s 开头的分数数据 */
  const scoreData = [];
  for (const key in stats) {
    if (key.startsWith('s') && key.length > 1) {
      const score = parseInt(key.substring(1));
      if (!isNaN(score) && stats[key] > 0) {
        scoreData.push({ score, count: stats[key] });
      }
    }
  }
  // 按分数排序
  scoreData.sort((a, b) => a.score - b.score);

  /* 计算总提交数 */
  const totalSubmissions = statusKeys.reduce((sum, k) => sum + stats[k], 0);

  /* 添加统计卡片 */
  const summaryHtml = `
    <div class="hili-stats-summary">
      <div class="hili-stat-card" style="background: linear-gradient(135deg, #667eea, #764ba2)">
        <div class="hili-stat-value">${totalSubmissions}</div>
        <div class="hili-stat-label">总提交</div>
      </div>
      <div class="hili-stat-card" style="background: linear-gradient(135deg, #52c41a, #73d13d)">
        <div class="hili-stat-value">${stats.AC || 0}</div>
        <div class="hili-stat-label">通过数</div>
      </div>
      <div class="hili-stat-card" style="background: linear-gradient(135deg, #fa8c16, #ffc53d)">
        <div class="hili-stat-value">${totalSubmissions > 0 ? ((stats.AC || 0) / totalSubmissions * 100).toFixed(1) : 0}%</div>
        <div class="hili-stat-label">通过率</div>
      </div>
    </div>
  `;
  statusContainer.insertAdjacentHTML('beforeend', summaryHtml);

  /* 等一帧，保证尺寸正常 */
  requestAnimationFrame(() => {
    /* 状态分布图 - 完整圆形图，固定尺寸 */
    new Chart(document.getElementById('statusChart').getContext('2d'), {
      type: 'pie',
      data: {
        labels: statusKeys,
        datasets: [{
          data: statusKeys.map(k => stats[k]),
          backgroundColor: statusKeys.map(k => COLOR[k]),
          borderWidth: 3,
          borderColor: '#fff',
        }],
      },
      options: {
        responsive: false,
        maintainAspectRatio: true,
        aspectRatio: 1,
        plugins: {
          legend: {
            position: 'bottom',
            labels: {
              padding: 15,
              font: { size: 12 },
              usePointStyle: true,
            }
          },
          tooltip: {
            callbacks: {
              label: function(context) {
                const label = context.label || '';
                const value = context.parsed || 0;
                const total = context.dataset.data.reduce((a, b) => a + b, 0);
                const percentage = ((value / total) * 100).toFixed(1);
                return `${label}: ${value} (${percentage}%)`;
              }
            }
          }
        },
      },
    });

    /* 分数分布图 - 面积图 */
    if (scoreData.length > 0) {
      new Chart(document.getElementById('scoreChart').getContext('2d'), {
        type: 'line',
        data: {
          labels: scoreData.map(d => d.score + '分'),
          datasets: [{
            label: '提交数量',
            data: scoreData.map(d => d.count),
            borderColor: '#5b8cff',
            backgroundColor: 'rgba(91, 140, 255, 0.1)',
            borderWidth: 3,
            tension: 0.4,
            fill: true,
            pointRadius: 5,
            pointBackgroundColor: '#fff',
            pointBorderColor: '#5b8cff',
            pointBorderWidth: 2,
            pointHoverRadius: 7,
          }],
        },
        options: {
          responsive: true,
          maintainAspectRatio: false,
          scales: {
            y: {
              beginAtZero: true,
              grid: {
                color: 'rgba(0, 0, 0, 0.05)',
              },
              ticks: {
                font: { size: 11 },
              }
            },
            x: {
              grid: {
                display: false,
              },
              ticks: {
                font: { size: 11 },
              }
            }
          },
          plugins: {
            legend: {
              display: false,
            },
            tooltip: {
              backgroundColor: 'rgba(0, 0, 0, 0.8)',
              padding: 12,
              titleFont: { size: 13 },
              bodyFont: { size: 12 },
            }
          },
          interaction: {
            intersect: false,
            mode: 'index',
          },
        },
      });
    } else {
      // 如果没有分数数据，显示提示信息
      document.getElementById('scoreChart').parentElement.innerHTML = `
        <div class="hili-chart-title">得分分布趋势</div>
        <div style="display: flex; align-items: center; justify-content: center; height: 280px; color: #999; font-size: 14px;">
          暂无分数统计数据
        </div>
      `;
    }
  });
}