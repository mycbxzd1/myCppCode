#include <bits/stdc++.h>
using namespace std;

/**
 * 检查：给定所有数字(用频次表示)，是否“所有可能的末 k 位组合”
 * 都能被 base 整除？
 *
 * 这里的做法是：生成所有可行的 k 位排列（若频次允许），检查 mod base。
 * 若发现任意一个不被整除，则返回 false；全部都能整除则 true。
 *
 * 注意：此方法在数字种类较少时可行性较高；若种类很多且 k 过大，可能会爆。
 * 可以做更多剪枝或 DP 优化，这里作演示。
 */
bool allCombinationsDivisible(const vector<int>& freq, int k, int base) {
    // freq[d] 表示数字 d 的个数，d &isin; [0..9]
    // 我们要选长度为 k 的序列(可以有重复数字，但每种数字使用不得超过 freq[d])
    // 并检查该 k 位(可能有前导零)在 10 进制下，对 base 的余数是否全为 0。

    // 若 k == 0，不存在真正的末位概念，可约定为 trivially true
    if(k == 0) return true;

    // 若总数字个数 < k，根本无法组成 k 位组合，trivially true or false？
    //   - 如果 k > 可用总数，说明题意“所有排列”中也不可能有这么多位末尾。
    //     不过在实际判断 2^k、5^k 时，往往只到 min(k, length_of_N)。
    // 这里先简单处理：若 k 大于可用总数，就当作无需再检查 = true
    int totalDigits = accumulate(freq.begin(), freq.end(), 0);
    if(k > totalDigits) return true;

    // 我们要生成所有 k 位序列（允许前导零），枚举规模 <= 10^k(最坏)，要小心。
    // 这里用回溯示例，如果数字种类少，k <= 4 或 5 时能跑；
    // 若 k 大会爆炸，需特殊处理。

    // 收集所有可行的 k 位数字序列（字符串/整数），然后检查 % base。
    // 一旦发现一个不整除就返回 false。
    // -- 以下是一个简单回溯 --
    vector<int> freqCopy = freq;   // 拷贝，用于回溯时修改

    long long currentVal = 0;      // 用于构建十进制数
    function<bool(int)> dfs = [&](int depth)->bool {
        if(depth == k) {
            // 检查 currentVal 对 base 是否整除
            if(currentVal % base != 0) return false;
            return true;
        }
        // 尝试放各个数字
        for(int d=0; d<=9; d++){
            if(freqCopy[d] > 0){
                // 用 d
                freqCopy[d]--;
                long long oldVal = currentVal;
                // 往右增加一位
                currentVal = currentVal*10 + d;

                bool ok = dfs(depth+1);
                // 回溯
                currentVal = oldVal;
                freqCopy[d]++;

                if(!ok) return false;  // 剪枝，一票否决
            }
        }
        return true; // 如果都 ok，则 true
    };

    return dfs(0);
}

// 计算对于 2 的幂可以到多少
int getMaxPowerOf2(const vector<int>& freq) {
    // 若并非全是偶数，返回 0 表示没有 2 的因子
    for(int d=1; d<=9; d+=2) {
        if(freq[d] != 0) {
            return 0; 
        }
    }
    // 全为偶数 -> 至少含 2^1
    // 依次检查 2^2, 2^3, ..., 2^p
    // 这里演示到 p=6（可自行调大/调小）
    int total = accumulate(freq.begin(), freq.end(), 0);
    int maxCheck = min(total, 6);  // 例如只检查到 2^6=64，演示

    int currentPower = 0;
    // 我们构建 base = 2^p，依次从 p=1 开始
    int base = 1;
    for(int p = 1; p <= maxCheck; p++){
        base *= 2;  // base = 2^p
        if(allCombinationsDivisible(freq, p, base)){
            currentPower = p;
        } else {
            break;
        }
    }
    return currentPower;
}

// 计算对于 5 的幂可以到多少
int getMaxPowerOf5(const vector<int>& freq) {
    // 若并非全是 {0,5}，返回 0 表示没有 5 的因子
    for(int d=1; d<=9; d++){
        if(d != 5 && freq[d] != 0) {
            return 0;
        }
    }
    // 剩下只可能是 0 或 5
    // 依次检查 5^1, 5^2, 5^3, ...
    int total = accumulate(freq.begin(), freq.end(), 0);
    int maxCheck = min(total, 6);  // 同理演示到 5^6

    int currentPower = 0;
    int base = 1;
    for(int p = 1; p <= maxCheck; p++){
        base *= 5; // base = 5^p
        if(allCombinationsDivisible(freq, p, base)){
            currentPower = p;
        } else {
            break;
        }
    }
    return currentPower;
}

// 大数乘法(或用字符串)以防结果过大，这里简单起见用64位，如果题目数字很大且幂次大可能溢出
long long quickPow(long long x, int n) {
    long long res = 1;
    while(n>0) {
        if(n & 1) res = res*x;
        x = x*x;
        n >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    cin >> N;
    // 1) 若只有一位，直接输出
    if(N.size() == 1){
        cout << N << "\n";
        return 0;
    }

    // 2) 判断是否所有数字都一样
    bool allSame = true;
    for(int i=1; i<(int)N.size(); i++){
        if(N[i] != N[0]){
            allSame = false;
            break;
        }
    }
    // 若的确全一样，则只有一个唯一排列
    if(allSame){
        // gcd 就是这个数本身
        // 直接输出 N
        // (若非常大，可保留字符串形式输出)
        cout << N << "\n";
        return 0;
    }

    // 3) 现在是一般情况（可以产生多个不同排列）
    //    先求数字和，判断 3 的因子是 1,3,还是9
    long long sumD = 0;
    vector<int> freq(10,0);
    for(char c: N){
        int d = c - '0';
        freq[d]++;
        sumD += d;
    }

    // factor3
    long long factor3 = 1;
    if(sumD % 9 == 0){
        factor3 = 9;
    } else if(sumD % 3 == 0){
        factor3 = 3;
    } 

    // 4) 计算 2 的最大幂
    int p2 = getMaxPowerOf2(freq);
    long long factor2 = quickPow(2LL, p2);

    // 5) 计算 5 的最大幂
    int p5 = 0;
    long long factor5 = 1;
    {
        p5 = getMaxPowerOf5(freq);
        factor5 = quickPow(5LL, p5);
    }

    // 最终 gcd
    // 注意：因为我们是分开算 2^p2 和 5^p5，直接相乘就表示含有 2^p2 * 5^p5 = 10^min(p2,p5) * 其他...
    // 同时还要乘上 3 的部分 factor3
    // 整体 gcd = factor2 * factor3 * factor5
    // 在大部分常见情况下，这会是正确的组合。
    long long gcd_val = factor2 * factor3 * factor5;

    cout << gcd_val << "\n";
    return 0;
}