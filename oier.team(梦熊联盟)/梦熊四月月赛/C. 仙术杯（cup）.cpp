#include<bits/stdc++.h> 
#define int long long 
using namespace std;
int n, k,s[1010]; 
int findmax() {
    deque<int> miq,mxq; // ��Сֵ���С����ֵ����
    int ms = 0;
    for (int i = 1; i <= n; ++i) {
        // ά����Сֵ����
        while (!miq.empty() && miq.front() <= i - k) {
            miq.pop_front(); // ɾ��������Χ��Ԫ��
        }
        // ά�����ֵ����
        while (!mxq.empty() && mxq.front() <= i - k) {
            mxq.pop_front(); // ɾ��������Χ��Ԫ��
        }
        // ������Сֵ���еĵ���˳��
        while (!miq.empty() && s[i] <= s[miq.back()]) {
            miq.pop_back(); // ɾ�������бȵ�ǰԪ�ش��Ԫ��
        }
        miq.push_back(i); // ����ǰԪ���±�������

        // �������ֵ���еĵݼ�˳��
        while (!mxq.empty() && s[i] >= s[mxq.back()]) {
            mxq.pop_back(); // ɾ�������бȵ�ǰԪ��С��Ԫ��
        }
        mxq.push_back(i); // ����ǰԪ���±�������

        // �����ȴﵽkʱ��ʼ��������
        if (i >= k) {
            int mn = s[miq.front()]; // ��ǰ����Сֵ
            int mx = s[mxq.front()]; // ��ǰ�����ֵ
            ms = max(ms, mn + mx); // ��������
        }
    }
    return ms;
}
signed main() {
    cin >> n >> k; 
    for (int i = 1; i <= n; i++)cin >> s[i];
    cout <<findmax();
}

