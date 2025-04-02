#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const int INF = 1e8;

// 边的结构体，记录两个端点、以及两个权值 a 和 b
struct Edge
{
    int u, v, a, b;
    Edge() {}
    Edge(int _u, int _v, int _a, int _b) : u(_u), v(_v), a(_a), b(_b) {}
};

// 并查集类，用于维护图的连通性
class DSU
{
public:
    vector<int> parent;

    DSU(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (x != y)
            parent[x] = y;
    }
};

// 链剖树（Link-Cut Tree）节点结构体
struct Node
{
    int ch[2];  // 左右子节点编号
    int parent; // 父节点编号
    int val;    // 当前节点的权值（仅对边节点有效）
    int maxId;  // 子树中权值最大的节点编号（包含自身）
    bool rev;   // 标记是否需要翻转子树

    Node() : parent(0), val(0), maxId(0), rev(false)
    {
        ch[0] = ch[1] = 0;
    }
};

// 链剖树类，支持常见的操作：旋转、伸展、接入、换根、连边、断边等
class LinkCutTree
{
public:
    vector<Node> tree;
    // 构造时给定总节点数（包括原图结点和边结点）
    LinkCutTree(int n)
    {
        tree.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            tree[i].maxId = i;
    }

    // 判断 x 是否为其父节点的非虚子节点
    bool isRoot(int x)
    {
        int p = tree[x].parent;
        return tree[p].ch[0] != x && tree[p].ch[1] != x;
    }

    // 更新节点 x 的信息，由左右子树及自身确定子树中最大权值节点
    void pushUp(int x)
    {
        tree[x].maxId = x;
        for (int i = 0; i < 2; ++i)
        {
            int c = tree[x].ch[i];
            if (c && tree[tree[c].maxId].val > tree[tree[x].maxId].val)
                tree[x].maxId = tree[c].maxId;
        }
    }

    // 下传翻转标记
    void pushDown(int x)
    {
        if (tree[x].rev)
        {
            for (int i = 0; i < 2; ++i)
                reverseChild(tree[x].ch[i]);
            tree[x].rev = false;
        }
    }

    // 对节点 x 执行翻转操作
    void reverseChild(int x)
    {
        if (!x)
            return;
        swap(tree[x].ch[0], tree[x].ch[1]);
        tree[x].rev ^= true;
    }

    // 旋转操作
    void rotate(int x)
    {
        int p = tree[x].parent, g = tree[p].parent;
        int k = (tree[p].ch[1] == x);
        if (!isRoot(p))
            tree[g].ch[tree[g].ch[1] == p] = x;
        tree[x].parent = g;
        tree[p].ch[k] = tree[x].ch[k ^ 1];
        if (tree[x].ch[k ^ 1])
            tree[tree[x].ch[k ^ 1]].parent = p;
        tree[x].ch[k ^ 1] = p;
        tree[p].parent = x;
        pushUp(p);
        pushUp(x);
    }

    // 伸展操作，将 x 移动到 splay 树的根
    void splay(int x)
    {
        vector<int> stack;
        int cur = x;
        stack.push_back(cur);
        while (!isRoot(cur))
        {
            cur = tree[cur].parent;
            stack.push_back(cur);
        }
        // 下传所有标记
        for (int i = stack.size() - 1; i >= 0; --i)
            pushDown(stack[i]);
        while (!isRoot(x))
        {
            int p = tree[x].parent, g = tree[p].parent;
            if (!isRoot(p))
            {
                if ((tree[p].ch[0] == x) ^ (tree[g].ch[0] == p))
                    rotate(x);
                else
                    rotate(p);
            }
            rotate(x);
        }
    }

    // 接入操作
    void access(int x)
    {
        int last = 0;
        while (x)
        {
            splay(x);
            tree[x].ch[1] = last;
            pushUp(x);
            last = x;
            x = tree[x].parent;
        }
    }

    // 将 x 设为根
    void makeRoot(int x)
    {
        access(x);
        splay(x);
        reverseChild(x);
    }

    // 寻找 x 所在树的根节点
    int findRoot(int x)
    {
        access(x);
        splay(x);
        while (tree[x].ch[0])
        {
            pushDown(x);
            x = tree[x].ch[0];
        }
        splay(x);
        return x;
    }

    // 分离 x 到 y 的路径（将 y 作为根后，x 就在 y 的左子树中）
    void split(int x, int y)
    {
        makeRoot(x);
        access(y);
        splay(y);
    }

    // 连边：将 x 和 y 连接起来（假设它们不在同一树中）
    void link(int x, int y)
    {
        makeRoot(x);
        if (findRoot(y) != x)
            tree[x].parent = y;
    }

    // 断边：断开 x 与 y 之间的边
    void cut(int x, int y)
    {
        makeRoot(x);
        if (findRoot(y) == x && tree[y].parent == x && tree[y].ch[0] == 0)
        {
            tree[x].ch[1] = 0;
            tree[y].parent = 0;
            pushUp(x);
        }
    }
};

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m + 1);
    // 原图节点编号为 1~n，边节点编号从 n+1 开始
    for (int i = 1; i <= m; ++i)
    {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        edges[i] = Edge(u, v, a, b);
    }

    // 按照 a 权值排序
    sort(edges.begin() + 1, edges.end(), [](const Edge &e1, const Edge &e2)
         { return e1.a < e2.a; });

    // 总节点数 = 原图结点数 + 边结点数
    int totalNodes = n + m;
    LinkCutTree lct(totalNodes);

    // 初始化边节点的权值（仅对边节点有效），原图结点默认权值为 0
    for (int i = n + 1; i <= totalNodes; ++i)
        lct.tree[i].val = edges[i - n].b, lct.tree[i].maxId = i;

    DSU dsu(n);

    int res = INF;
    // 遍历所有边（按照 a 从小到大）
    for (int i = 1; i <= m; ++i)
    {
        int u = edges[i].u, v = edges[i].v;
        int a = edges[i].a, b = edges[i].b;
        int edgeNode = n + i; // 边节点的编号

        // 如果 u, v 已经连通，则尝试优化已有边
        if (dsu.find(u) == dsu.find(v))
        {
            lct.split(u, v);
            int maxEdgeId = lct.tree[v].maxId;
            if (lct.tree[maxEdgeId].val > b)
            {
                // 删除权值更大的边
                int oldEdgeIndex = maxEdgeId - n;
                lct.cut(edges[oldEdgeIndex].u, maxEdgeId);
                lct.cut(maxEdgeId, edges[oldEdgeIndex].v);
                // 添加当前边
                lct.link(u, edgeNode);
                lct.link(edgeNode, v);
            }
        }
        else
        {
            // u,v不连通，直接加入当前边
            dsu.merge(u, v);
            lct.link(u, edgeNode);
            lct.link(edgeNode, v);
        }

        // 如果 1 和 n 已经连通，则尝试更新答案
        if (dsu.find(1) == dsu.find(n))
        {
            lct.split(1, n);
            int curMaxEdgeId = lct.tree[n].maxId;
            res = min(res, a + lct.tree[curMaxEdgeId].val);
        }
    }

    cout << (res == INF ? -1 : res) << "\n";
    return 0;
}
