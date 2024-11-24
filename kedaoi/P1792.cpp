/*
 * 边带权并查集
 *
 * 扩展域并查集
 *
 * 把每个动物x拆成3个节点，同类域x_self、捕食域x_eat、天敌域x_enemy
 *
 * 1. 如果一句话说“x和y是同类”，则合并x_self和y_self、x_eat和y_eat、x_enemy和y_enemy
 * 2. 如果一句话说“x吃y”，说明x捕食的物种和y是同类，x的同类是y的天敌，x的天敌是y捕食的物种
 *                     合并x_eat和y_self、    x_self和y_enemy、x_enemy和y_eat
 *
 * 在处理每句话之前，要先检查这句话的真假：
 * 有以下两种情况与“x和y是同类”矛盾：
 * 1. x_eat和y_self在同一集合，说明x吃y
 * 2. x_self和y_eat在同一集合，说明y吃x
 * 类似地，有以下两种情况与“x吃y”矛盾：
 * 1. x_self和y_self在同一集合，说明x和y是同类
 * 2. x_self和y_eat在同一集合，说明y吃x
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
int n, k, ans;
int fa[N * 3];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= 3 * n; i++) fa[i] = i; // Initialize the whole array

    while (k--) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (x > n || y > n || (op == 2 && x == y)) {
            ++ans;
            continue;
        }
        if (op == 1 && (find(x + n) == find(y) || find(x) == find(y + n))) {
            ++ans;
            continue;
        }
        if (op == 2 && (find(x) == find(y) || find(x) == find(y + n))) {
            ++ans;
            continue;
        }

        if (op == 1) {
            fa[find(x)] = find(y);        // Union self and self
            fa[find(x + n)] = find(y + n); // Union eat and eat
            fa[find(x + 2 * n)] = find(y + 2 * n); // Union enemy and enemy
        } else {
            fa[find(x)] = find(y + 2 * n); // Union self and enemy
            fa[find(x + n)] = find(y);     // Union eat and self
            fa[find(x + 2 * n)] = find(y + n); // Union enemy and eat
        }
    }
    cout << ans << endl;
    return 0;
}
