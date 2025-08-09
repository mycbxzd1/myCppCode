#include <windows.h>
#include <vector>
#include <random>
#include <string>
#include <chrono>

// 游戏常量
const int BOARD_WIDTH = 16;
const int BOARD_HEIGHT = 16;
const int MINE_COUNT = 40;
const int CELL_SIZE = 25;
const int WINDOW_WIDTH = BOARD_WIDTH * CELL_SIZE + 20;
const int WINDOW_HEIGHT = BOARD_HEIGHT * CELL_SIZE + 100;

// 窗口和游戏状态
HWND hWnd;
HDC hdc, memDC;
HBITMAP memBitmap, oldBitmap;
bool gameOver = false;
bool gameWon = false;
bool firstClick = true;
int flagCount = 0;
int revealedCount = 0;
std::chrono::steady_clock::time_point gameStartTime;
int gameTime = 0;

// 游戏格子状态
enum CellState {
    HIDDEN,
    REVEALED,
    FLAGGED
};

struct Cell {
    bool hasMine;
    int neighborMines;
    CellState state;
    
    Cell() : hasMine(false), neighborMines(0), state(HIDDEN) {}
};

std::vector<std::vector<Cell>> board(BOARD_HEIGHT, std::vector<Cell>(BOARD_WIDTH));

// 函数声明
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void InitializeGame();
void PlaceMines(int firstX, int firstY);
void CalculateNeighbors();
void RevealCell(int x, int y);
void FlagCell(int x, int y);
void DrawBoard();
void DrawCell(int x, int y);
void DrawFlag(int x, int y);
void CheckWinCondition();
void ResetGame();
void UpdateTimer();
bool IsValidPosition(int x, int y);
void InitializeDoubleBuffering();
void CleanupDoubleBuffering();
void DrawTextUTF8(HDC hdc, int x, int y, const char* text);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 设置控制台代码页为UTF-8（如果有控制台的话）
    SetConsoleOutputCP(CP_UTF8);
    
    // 注册窗口类
    const char* CLASS_NAME = "MinesweeperWindow";
    
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    
    RegisterClass(&wc);
    
    // 创建窗口 - 使用宽字符版本
    hWnd = CreateWindowW(
        L"MinesweeperWindow",
        L"扫雷游戏 - Minesweeper",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        NULL, NULL, hInstance, NULL
    );
    
    if (hWnd == NULL) {
        return 0;
    }
    
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    
    // 初始化双缓冲和游戏
    InitializeDoubleBuffering();
    InitializeGame();
    
    // 设置定时器，每秒更新一次时间
    SetTimer(hWnd, 1, 1000, NULL);
    
    // 消息循环
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    CleanupDoubleBuffering();
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            KillTimer(hwnd, 1);
            PostQuitMessage(0);
            return 0;
            
        case WM_TIMER:
            if (wParam == 1 && !gameOver && !firstClick) {
                UpdateTimer();
                InvalidateRect(hwnd, NULL, FALSE);
            }
            return 0;
            
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC paintDC = BeginPaint(hwnd, &ps);
            
            // 绘制到内存DC
            DrawBoard();
            
            // 将内存DC内容复制到屏幕
            BitBlt(paintDC, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, memDC, 0, 0, SRCCOPY);
            
            EndPaint(hwnd, &ps);
            return 0;
        }
        
        case WM_LBUTTONDOWN: {
            if (gameOver) {
                ResetGame();
                InvalidateRect(hwnd, NULL, FALSE);
                return 0;
            }
            
            int mouseX = LOWORD(lParam);
            int mouseY = HIWORD(lParam);
            
            if (mouseY >= 60) {  // 游戏区域开始位置
                int x = (mouseX - 10) / CELL_SIZE;
                int y = (mouseY - 60) / CELL_SIZE;
                
                if (IsValidPosition(x, y)) {
                    if (firstClick) {
                        // 第一次点击，确保不踩雷
                        PlaceMines(x, y);
                        CalculateNeighbors();
                        firstClick = false;
                        gameStartTime = std::chrono::steady_clock::now();
                    }
                    
                    RevealCell(x, y);
                    CheckWinCondition();
                    InvalidateRect(hwnd, NULL, FALSE);
                }
            }
            return 0;
        }
        
        case WM_RBUTTONDOWN: {
            if (gameOver || firstClick) return 0;
            
            int mouseX = LOWORD(lParam);
            int mouseY = HIWORD(lParam);
            
            if (mouseY >= 60) {  // 游戏区域开始位置
                int x = (mouseX - 10) / CELL_SIZE;
                int y = (mouseY - 60) / CELL_SIZE;
                
                if (IsValidPosition(x, y)) {
                    FlagCell(x, y);
                    InvalidateRect(hwnd, NULL, FALSE);
                }
            }
            return 0;
        }
        
        case WM_KEYDOWN:
            if (wParam == VK_SPACE || wParam == 'R') {
                ResetGame();
                InvalidateRect(hwnd, NULL, FALSE);
            }
            return 0;
    }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void DrawTextUTF8(HDC hdc, int x, int y, const char* text) {
    // 将UTF-8字符串转换为宽字符
    int wideSize = MultiByteToWideChar(CP_UTF8, 0, text, -1, NULL, 0);
    if (wideSize > 0) {
        wchar_t* wideText = new wchar_t[wideSize];
        MultiByteToWideChar(CP_UTF8, 0, text, -1, wideText, wideSize);
        
        // 使用宽字符版本的文本输出函数
        TextOutW(hdc, x, y, wideText, wcslen(wideText));
        
        delete[] wideText;
    }
}

void InitializeDoubleBuffering() {
    HDC screenDC = GetDC(hWnd);
    memDC = CreateCompatibleDC(screenDC);
    memBitmap = CreateCompatibleBitmap(screenDC, WINDOW_WIDTH, WINDOW_HEIGHT);
    oldBitmap = (HBITMAP)SelectObject(memDC, memBitmap);
    ReleaseDC(hWnd, screenDC);
}

void CleanupDoubleBuffering() {
    SelectObject(memDC, oldBitmap);
    DeleteObject(memBitmap);
    DeleteDC(memDC);
}

void InitializeGame() {
    // 重置游戏状态
    gameOver = false;
    gameWon = false;
    firstClick = true;
    flagCount = 0;
    revealedCount = 0;
    gameTime = 0;
    
    // 初始化游戏板
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            board[y][x] = Cell();
        }
    }
}

void PlaceMines(int firstX, int firstY) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(0, BOARD_WIDTH - 1);
    std::uniform_int_distribution<> disY(0, BOARD_HEIGHT - 1);
    
    int minesPlaced = 0;
    while (minesPlaced < MINE_COUNT) {
        int x = disX(gen);
        int y = disY(gen);
        
        // 确保第一次点击的位置和周围不放置地雷
        bool tooClose = false;
        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if (x == firstX + dx && y == firstY + dy) {
                    tooClose = true;
                    break;
                }
            }
            if (tooClose) break;
        }
        
        if (!board[y][x].hasMine && !tooClose) {
            board[y][x].hasMine = true;
            minesPlaced++;
        }
    }
}

void CalculateNeighbors() {
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            if (!board[y][x].hasMine) {
                int count = 0;
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (IsValidPosition(nx, ny) && board[ny][nx].hasMine) {
                            count++;
                        }
                    }
                }
                board[y][x].neighborMines = count;
            }
        }
    }
}

void RevealCell(int x, int y) {
    if (!IsValidPosition(x, y) || board[y][x].state != HIDDEN) {
        return;
    }
    
    board[y][x].state = REVEALED;
    revealedCount++;
    
    if (board[y][x].hasMine) {
        gameOver = true;
        // 显示所有地雷
        for (int cy = 0; cy < BOARD_HEIGHT; cy++) {
            for (int cx = 0; cx < BOARD_WIDTH; cx++) {
                if (board[cy][cx].hasMine) {
                    board[cy][cx].state = REVEALED;
                }
            }
        }
        return;
    }
    
    // 如果是空格子，自动揭开周围的格子
    if (board[y][x].neighborMines == 0) {
        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                RevealCell(x + dx, y + dy);
            }
        }
    }
}

void FlagCell(int x, int y) {
    if (!IsValidPosition(x, y) || board[y][x].state == REVEALED) {
        return;
    }
    
    if (board[y][x].state == HIDDEN) {
        board[y][x].state = FLAGGED;
        flagCount++;
    } else if (board[y][x].state == FLAGGED) {
        board[y][x].state = HIDDEN;
        flagCount--;
    }
}

void UpdateTimer() {
    if (!firstClick && !gameOver) {
        auto now = std::chrono::steady_clock::now();
        gameTime = std::chrono::duration_cast<std::chrono::seconds>(now - gameStartTime).count();
    }
}

void DrawBoard() {
    // 设置背景色
    RECT rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    FillRect(memDC, &rect, (HBRUSH)(COLOR_WINDOW + 1));
    
    // 设置字体和颜色
    SetTextColor(memDC, RGB(0, 0, 0));
    SetBkMode(memDC, TRANSPARENT);
    
    // 创建中文字体
    HFONT chineseFont = CreateFontW(
        16,                        // 字体高度
        0,                         // 字体宽度
        0,                         // 字体角度
        0,                         // 基线角度
        FW_NORMAL,                 // 字体粗细
        FALSE,                     // 斜体
        FALSE,                     // 下划线
        FALSE,                     // 删除线
        GB2312_CHARSET,            // 字符集
        OUT_DEFAULT_PRECIS,        // 输出精度
        CLIP_DEFAULT_PRECIS,       // 裁剪精度
        DEFAULT_QUALITY,           // 输出质量
        DEFAULT_PITCH | FF_SWISS,  // 字体系列
        L"微软雅黑"                 // 字体名称
    );
    
    HFONT oldFont = (HFONT)SelectObject(memDC, chineseFont);
    
    // 第一行：地雷计数和时间
    char info1[100];
    sprintf(info1, "地雷: %d   时间: %ds", MINE_COUNT - flagCount, gameTime);
    DrawTextUTF8(memDC, 10, 10, info1);
    
    // 第二行：操作提示或游戏状态
    const char* info2;
    if (firstClick) {
        info2 = "点击任意位置开始游戏 | 左键揭开，右键插旗 | 空格键重新开始";
    } else if (gameOver) {
        info2 = gameWon ? "恭喜获胜！点击任意位置或按空格键重新开始" : 
                         "游戏结束！点击任意位置或按空格键重新开始";
    } else {
        info2 = "左键点击揭开，右键插旗 | 空格键重新开始";
    }
    DrawTextUTF8(memDC, 10, 30, info2);
    
    // 恢复原字体
    SelectObject(memDC, oldFont);
    DeleteObject(chineseFont);
    
    // 绘制游戏板
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            DrawCell(x, y);
        }
    }
}

void DrawCell(int x, int y) {
    int pixelX = 10 + x * CELL_SIZE;
    int pixelY = 60 + y * CELL_SIZE;
    
    RECT cellRect = {pixelX, pixelY, pixelX + CELL_SIZE, pixelY + CELL_SIZE};
    
    Cell& cell = board[y][x];
    
    if (cell.state == HIDDEN) {
        // 未揭开的格子 - 立体效果
        FillRect(memDC, &cellRect, CreateSolidBrush(RGB(192, 192, 192)));
        
        // 绘制立体边框
        HPEN lightPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
        HPEN darkPen = CreatePen(PS_SOLID, 1, RGB(128, 128, 128));
        
        SelectObject(memDC, lightPen);
        MoveToEx(memDC, pixelX, pixelY + CELL_SIZE - 1, NULL);
        LineTo(memDC, pixelX, pixelY);
        LineTo(memDC, pixelX + CELL_SIZE - 1, pixelY);
        
        SelectObject(memDC, darkPen);
        MoveToEx(memDC, pixelX + CELL_SIZE - 1, pixelY, NULL);
        LineTo(memDC, pixelX + CELL_SIZE - 1, pixelY + CELL_SIZE - 1);
        LineTo(memDC, pixelX, pixelY + CELL_SIZE - 1);
        
        DeleteObject(lightPen);
        DeleteObject(darkPen);
        
    } else if (cell.state == FLAGGED) {
        // 插旗的格子 - 立体效果 + 旗子
        FillRect(memDC, &cellRect, CreateSolidBrush(RGB(192, 192, 192)));
        
        // 绘制立体边框
        HPEN lightPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
        HPEN darkPen = CreatePen(PS_SOLID, 1, RGB(128, 128, 128));
        
        SelectObject(memDC, lightPen);
        MoveToEx(memDC, pixelX, pixelY + CELL_SIZE - 1, NULL);
        LineTo(memDC, pixelX, pixelY);
        LineTo(memDC, pixelX + CELL_SIZE - 1, pixelY);
        
        SelectObject(memDC, darkPen);
        MoveToEx(memDC, pixelX + CELL_SIZE - 1, pixelY, NULL);
        LineTo(memDC, pixelX + CELL_SIZE - 1, pixelY + CELL_SIZE - 1);
        LineTo(memDC, pixelX, pixelY + CELL_SIZE - 1);
        
        DeleteObject(lightPen);
        DeleteObject(darkPen);
        
        // 绘制旗子
        DrawFlag(x, y);
        
    } else if (cell.state == REVEALED) {
        if (cell.hasMine) {
            // 地雷 - 红色背景
            FillRect(memDC, &cellRect, CreateSolidBrush(RGB(255, 100, 100)));
            FrameRect(memDC, &cellRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
            
            // 绘制地雷符号 - 使用星号代替emoji
            SetTextColor(memDC, RGB(0, 0, 0));
            SetBkMode(memDC, TRANSPARENT);
            HFONT boldFont = CreateFontA(16, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, 
                                       ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
                                       DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
            HFONT oldFont = (HFONT)SelectObject(memDC, boldFont);
            TextOutA(memDC, pixelX + 8, pixelY + 4, "*", 1);
            SelectObject(memDC, oldFont);
            DeleteObject(boldFont);
        } else {
            // 普通揭开的格子 - 凹陷效果
            FillRect(memDC, &cellRect, CreateSolidBrush(RGB(229, 229, 229)));
            
            // 绘制凹陷边框
            HPEN darkPen = CreatePen(PS_SOLID, 1, RGB(128, 128, 128));
            SelectObject(memDC, darkPen);
            
            MoveToEx(memDC, pixelX, pixelY + CELL_SIZE - 1, NULL);
            LineTo(memDC, pixelX, pixelY);
            LineTo(memDC, pixelX + CELL_SIZE - 1, pixelY);
            
            DeleteObject(darkPen);
            
            if (cell.neighborMines > 0) {
                // 根据周围地雷数量设置不同颜色
                COLORREF colors[] = {
                    RGB(0, 0, 255),    // 1 - 蓝色
                    RGB(0, 128, 0),    // 2 - 绿色
                    RGB(255, 0, 0),    // 3 - 红色
                    RGB(128, 0, 128),  // 4 - 紫色
                    RGB(128, 0, 0),    // 5 - 深红色
                    RGB(0, 128, 128),  // 6 - 青色
                    RGB(0, 0, 0),      // 7 - 黑色
                    RGB(128, 128, 128) // 8 - 灰色
                };
                
                SetTextColor(memDC, colors[cell.neighborMines - 1]);
                SetBkMode(memDC, TRANSPARENT);
                
                // 使用粗体字体
                HFONT boldFont = CreateFontA(14, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, 
                                           ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
                                           DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
                HFONT oldFont = (HFONT)SelectObject(memDC, boldFont);
                
                char numStr[2];
                sprintf(numStr, "%d", cell.neighborMines);
                TextOutA(memDC, pixelX + 8, pixelY + 5, numStr, 1);
                
                SelectObject(memDC, oldFont);
                DeleteObject(boldFont);
            }
        }
    }
}

void DrawFlag(int x, int y) {
    int pixelX = 10 + x * CELL_SIZE;
    int pixelY = 60 + y * CELL_SIZE;
    
    // 绘制旗杆
    HPEN polePen = CreatePen(PS_SOLID, 2, RGB(139, 69, 19)); // 棕色旗杆
    HPEN oldPen = (HPEN)SelectObject(memDC, polePen);
    
    MoveToEx(memDC, pixelX + 12, pixelY + 20, NULL);
    LineTo(memDC, pixelX + 12, pixelY + 5);
    
    // 绘制旗面
    HBRUSH flagBrush = CreateSolidBrush(RGB(255, 0, 0)); // 红色旗面
    HBRUSH oldBrush = (HBRUSH)SelectObject(memDC, flagBrush);
    
    POINT flagPoints[] = {
        {pixelX + 12, pixelY + 5},
        {pixelX + 20, pixelY + 8},
        {pixelX + 12, pixelY + 12}
    };
    Polygon(memDC, flagPoints, 3);
    
    SelectObject(memDC, oldPen);
    SelectObject(memDC, oldBrush);
    DeleteObject(polePen);
    DeleteObject(flagBrush);
}

void CheckWinCondition() {
    if (gameOver) return;
    
    int totalCells = BOARD_WIDTH * BOARD_HEIGHT;
    if (revealedCount == totalCells - MINE_COUNT) {
        gameWon = true;
        gameOver = true;
    }
}

void ResetGame() {
    InitializeGame();
}

bool IsValidPosition(int x, int y) {
    return x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT;
}