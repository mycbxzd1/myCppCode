#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1005; // ��������С
int A[MAXN][MAXN]; // �����޽��������ÿ�����ӵĻ���
int dp[MAXN][MAXN]; // dp[i][j] ��ʾ����㵽����� (i, j) ����С����

int main() {
    int W, H, C;
    cin >> W >> H >> C;
    
    // �����޽��������ÿ�����ӵĻ���
    for (int i = 1; i <= W; ++i) {
        for (int j = 1; j <= H; ++j) {
            cin >> A[i][j];
        }
    }
    
    // ��ʼ�� dp ����Ϊһ���㹻���ֵ
    for (int i = 0; i <= W; ++i) {
        fill(dp[i], dp[i] + MAXN, 1e9);
    }
    
    // ��ʼ����� (1, 1) ����С����
    dp[1][1] = A[1][1];
    
    // ��̬�滮����ÿ�����ӵ���С����
    for (int i = 1; i <= W; ++i) {
        for (int j = 1; j <= H; ++j) {
            // ���Ϸ������ƶ�����
            if (i > 1)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + C);
            // ���󷽸����ƶ�����
            if (j > 1)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + C);
            // ���µ������ (i, j) ����С����
            dp[i][j] += A[i][j];
        }
    }
    
    // ��������յ� (W, H) ����С����
    cout << dp[W][H] << endl;
    
    return 0;
}

