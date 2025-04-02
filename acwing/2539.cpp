#include <bits/stdc++.h>
using namespace std;
const int N = 100010;

class dynamicTree
{
private:
    struct Node
    {
        int s[2], p; // 左右子节点、父节点
        int v;       // 节点本身的值
        int sum;     // 子树异或和
        int rev;     // 翻转标记
    } tr[N];
    int stk[N]; // 辅助splay的栈

    // 判断x是否为其所在splay树的根
    bool isroot(int x)
    {
        return tr[tr[x].p].s[0] != x && tr[tr[x].p].s[1] != x;
    }

    // 更新节点x的信息，维护子树异或和
    void pushup(int x)
    {
        tr[x].sum = tr[tr[x].s[0]].sum ^ tr[x].v ^ tr[tr[x].s[1]].sum;
    }

    // 翻转节点x的左右子树
    void pushrev(int x)
    {
        swap(tr[x].s[0], tr[x].s[1]);
        tr[x].rev ^= 1;
    }

    // 向下传递翻转标记
    void pushdown(int x)
    {
        if (tr[x].rev)
        {
            if (tr[x].s[0])
                pushrev(tr[x].s[0]);
            if (tr[x].s[1])
                pushrev(tr[x].s[1]);
            tr[x].rev = 0;
        }
    }

    // 标准旋转操作
    void rotate(int x)
    {
        int y = tr[x].p, z = tr[y].p;
        int k = (tr[y].s[1] == x);
        if (!isroot(y))
            tr[z].s[tr[z].s[1] == y] = x;
        tr[x].p = z;
        tr[y].s[k] = tr[x].s[k ^ 1];
        if (tr[x].s[k ^ 1])
            tr[tr[x].s[k ^ 1]].p = y;
        tr[x].s[k ^ 1] = y;
        tr[y].p = x;
        pushup(y);
        pushup(x);
    }

    // 将节点x旋转到splay树根
    void splay(int x)
    {
        int top = 0, r = x;
        stk[++top] = r;
        while (!isroot(r))
        {
            stk[++top] = r = tr[r].p;
        }
        while (top)
            pushdown(stk[top--]);
        while (!isroot(x))
        {
            int y = tr[x].p, z = tr[y].p;
            if (!isroot(y))
                if ((tr[y].s[0] == x) ^ (tr[z].s[0] == y))
                    rotate(x);
                else
                    rotate(y);
            rotate(x);
        }
    }

    // 访问操作，使x到根的路径成为右儿子链
    void access(int x)
    {
        int y = 0;
        for (; x; x = tr[x].p)
        {
            splay(x);
            tr[x].s[1] = y;
            pushup(x);
            y = x;
        }
    }

    // 将x作为整棵树的根（对树进行翻转）
    void makeroot(int x)
    {
        access(x);
        splay(x);
        pushrev(x);
    }

    // 找到x所在树的根
    int findroot(int x)
    {
        access(x);
        splay(x);
        while (tr[x].s[0])
        {
            pushdown(x);
            x = tr[x].s[0];
        }
        splay(x);
        return x;
    }

    // 内部的分裂操作：使x为根，然后将y作为splay的根，此时y的splay树表示路径
    void split_internal(int x, int y)
    {
        makeroot(x);
        access(y);
        splay(y);
    }

    // 内部的连接操作：将x和y连接
    void link_internal(int x, int y)
    {
        makeroot(x);
        if (findroot(y) != x)
            tr[x].p = y;
    }

    // 内部的断开操作：断开x和y之间的边
    void cut_internal(int x, int y)
    {
        makeroot(x);
        if (findroot(y) == x && tr[y].p == x && !tr[y].s[0])
        {
            tr[x].s[1] = 0;
            tr[y].p = 0;
            pushup(x);
        }
    }

public:
    int n;
    dynamicTree(int n) : n(n)
    {
        for (int i = 1; i <= n; i++)
        {
            tr[i].p = tr[i].s[0] = tr[i].s[1] = 0;
            tr[i].rev = 0;
            tr[i].v = 0;
            tr[i].sum = 0;
        }
    }
    void init(int i, int value)
    {
        tr[i].v = value;
        tr[i].sum = value;
    }
    int query(int x, int y)
    {
        split_internal(x, y);
        return tr[y].sum;
    }
    void update(int x, int value)
    {
        splay(x);
        tr[x].v = value;
        pushup(x);
    }
    void link(int x, int y)
    {
        link_internal(x, y);
    }
    void cut(int x, int y)
    {
        cut_internal(x, y);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    dynamicTree tree(n);
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        tree.init(i, val);
    }
    while (m--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0)
        {
            // 查询路径x到y的异或和
            cout << tree.query(x, y) << "\n";
        }
        else if (t == 1)
        {
            // 连接x和y
            tree.link(x, y);
        }
        else if (t == 2)
        {
            // 断开x和y之间的边
            tree.cut(x, y);
        }
        else if (t == 3)
        {
            // 修改x的值为y
            tree.update(x, y);
        }
    }
    return 0;
}
