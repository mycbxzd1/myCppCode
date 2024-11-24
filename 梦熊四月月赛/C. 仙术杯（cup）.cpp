#include<bits/stdc++.h> 
#define int long long 
using namespace std;
int n, k,s[1010]; 
int findmax() {
    deque<int> miq,mxq; // 最小值队列、最大值队列
    int ms = 0;
    for (int i = 1; i <= n; ++i) {
        // 维护最小值队列
        while (!miq.empty() && miq.front() <= i - k) {
            miq.pop_front(); // 删除超出范围的元素
        }
        // 维护最大值队列
        while (!mxq.empty() && mxq.front() <= i - k) {
            mxq.pop_front(); // 删除超出范围的元素
        }
        // 保持最小值队列的递增顺序
        while (!miq.empty() && s[i] <= s[miq.back()]) {
            miq.pop_back(); // 删除队列中比当前元素大的元素
        }
        miq.push_back(i); // 将当前元素下标加入队列

        // 保持最大值队列的递减顺序
        while (!mxq.empty() && s[i] >= s[mxq.back()]) {
            mxq.pop_back(); // 删除队列中比当前元素小的元素
        }
        mxq.push_back(i); // 将当前元素下标加入队列

        // 当长度达到k时开始计算最大和
        if (i >= k) {
            int mn = s[miq.front()]; // 当前的最小值
            int mx = s[mxq.front()]; // 当前的最大值
            ms = max(ms, mn + mx); // 更新最大和
        }
    }
    return ms;
}
signed main() {
    cin >> n >> k; 
    for (int i = 1; i <= n; i++)cin >> s[i];
    cout <<findmax();
}

