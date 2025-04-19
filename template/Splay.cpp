#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
class Splay
{
private:
    int root;                    /*根节点编号,用于标识 Splay 树的根节点. */
    int total;                   /*节点个数,表示树中所有节点的总数. */
    vector<int> father;          /*父节点数组,存储每个节点的直接父节点编号,便于在树操作过程中回溯至父节点. */
    vector<array<int, 2>> child; /*子节点数组,每个元素包含左右子节点的编号：child[i][0] 表示左子节点编号,child[i][1] 表示右子节点编号 */
    vector<int> value;           /*权值数组,存储每个节点的数值或权重,常用于节点之间的比较操作. */
    vector<int> count;           /*权值出现次数数组,记录每个权值在树中出现的次数,以支持处理重复元素的情况. */
    vector<int> size;            /*子树大小数组,表示以当前节点为根的子树中包含的节点总数,常用于统计和查询操作. */
public:
    /**
     * @brief 更新节点 x 的大小 (size)。
     *
     * 在改变节点位置后，调用此函数更新节点 x 的大小。
     *
     * @param x 表示需要更新大小的节点。
     */
    void maintain(int x)
    {
        size[x] = size[child[x][0]] + size[child[x][1]] + count[x];
    }
    /**
     * @brief 判断节点 x 是其父亲节点的右儿子还是左儿子
     *
     * @param x 欲被判断的节点
     *
     * @return 如果 x 是父节点的右子节点返回 true;否则返回 false.
     */
    bool get(int x)
    {
        return (x == child[father[x]][1]);
    }
    /**
     * @brief 清除节点 x 的所有信息
     *
     * 该函数将节点 x 的左右子节点、父节点、值、大小及计数器全部重置为 0。
     *
     * @param x 需要被清除的节点
     */
    void clear(int x)
    {
        child[x][0] = father[x] = child[x][1] = value[x] = size[x] = count[x] = 0;
    }
    /**
     * @brief 对节点进行旋转操作
     *
     * 此函数用于在平衡树中对节点进行旋转操作，
     * 将节点x与其父节点交换，从而调整树的结构和维护子树信息。
     *
     * @param x 欲被旋转的节点
     */
    void rotate(int x)
    {
        int y = father[x], z = father[y], flag = get(x);
        child[y][flag] = child[x][flag ^ 1];
        if (child[x][flag ^ 1])
            father[child[x][flag ^ 1]] = y;
        child[x][flag ^ 1] = y;
        father[y] = x;
        father[x] = z;
        if (z)
            child[z][(y == child[z][1])] = x;
        maintain(y);
        maintain(x);
    }
    /**
     * @brief 伸展操作，将节点 x 移动到根节点
     *
     * 本函数通过连续旋转操作，将节点 x 旋转到树根位置。
     *
     * @param x 欲被伸展的节点
     */
    void splay(int x)
    {
        for (int f = father[x]; f = father[x], f; rotate(x))
            if (father[f])
                rotate((get(x) == get(f)) ? f : x);
        root = x;
    }
    /**
     * @brief 将值 x 插入伸展树中
     *
     * @param x 欲插入的数值
     *
     * @note 如果树为空则创建根节点；否则根据大小比较找到插入位置，
     *       如果已存在则增加计数，若不存在则新建节点，并将新节点伸展到根。
     */
    void insert(int x)
    {
        if (root == 0)
        {
            value.push_back(x);
            count.push_back(1);
            size.push_back(1);
            father.push_back(0);
            child.push_back({0, 0});
            root = value.size() - 1;
        }
        int cur = root, f = 0;
        while (true)
        {
            if (value[cur] == x)
            {
                count[cur]++;
                maintain(cur);
                maintain(f);
                splay(cur);
                break;
            }
            f = cur;
            cur = child[cur][(value[cur] < x)];
            if (cur == 0)
            {
                value.push_back(x);
                count.push_back(1);
                size.push_back(1);
                father.push_back(f);
                child.push_back({0, 0});
                child[f][(value[f] < x)] = value.size() - 1;
                maintain(f);
                splay(value.size() - 1);
                break;
            }
        }
    }
    /**
     * @brief 查询 x 在树中的排名
     *
     * @param x 待查询的数值
     *
     * @return 返回 x 的排名（从 1 开始计数）
     *
     * @note 查询过程中会将对应节点伸展到根,遍历方式为中序遍历
     */
    int rank(int x)
    {
        int res = 0, cur = root;
        while (true)
        {
            if (x < value[cur])
                cur = child[cur][0];
            else
            {
                res += size[child[cur][0]];
                if (!cur)
                    return res + 1;
                if (x == value[cur])
                {
                    splay(cur);
                    return res + 1;
                }
                res += cnt[cur];
                cur = child[cur][1];
            }
        }
    }
    /**
     * @brief 查询排名为 k 的数（第 k 小的元素）
     *
     * @param k 欲查询的排名（从1开始计数）
     * @return 返回排名为 k 的节点的值
     *
     * @note 查询过程中会将目标节点伸展至根节点
     */
    int kth(int k)
    {
        int cur = root;
        while (true)
        {
            if (child[cur][0] && k <= size[child[cur][0]])
                cur = child[cur][0];
            else
            {
                k -= count[cur] + size[child[cur][0]];
                if (k <= 0)
                {
                    splay(cur);
                    return value[cur];
                }
                cur = child[cur][1];
            }
        }
    }
    /**
     * @brief 获取当前根节点的前驱节点索引
     *
     * @return 返回前驱节点的索引；若不存在前驱则返回 0。
     *
     * @note 查找过程中会将前驱节点伸展到根节点。
     */
    int pre()
    {
        int cur = child[root][0];
        if (!cur)
            return cur;
        while (child[cur][1])
            cur = child[cur][1];
        splay(cur);
        return cur;
    }
    /**
     * @brief 获取当前根节点的后继节点索引
     *
     * @return 返回后继节点的索引；若不存在后继则返回 0。
     *
     * @note 查找过程中会将后继节点伸展到根节点。
     */
    int nxt()
    {
        int cur = child[root][1];
        if (!cur)
            return cur;
        while (child[cur][0])
            cur = child[cur][0];
        splay(cur);
        return cur;
    }
    /**
     * @brief 删除节点 x
     *
     * @param x 要删除的节点索引
     *
     * @note 本函数首先将节点 x 伸展到根，然后根据节点计数和子节点情况执行删除：
     */
    void del(int x)
    {
        splay(x);
        if (count[root] > 1)
        {
            count[root]--;
            maintain(root);
            return;
        }
        if (child[root][0] == 0 && child[root][1] == 0)
        {
            clear(root);
            root = 0;
            return;
        }
        if (child[root][0] == 0)
        {
            int cur = root;
            root = child[root][1];
            father[root] = 0;
            clear(cur);
            return;
        }
        if (child[root][1] == 0)
        {
            int cur = root;
            root = child[root][0];
            father[root] = 0;
            clear(cur);
            return;
        }
        int cur = root;
        int k = pre();
        father[child[cur][1]] = k;
        child[k][1] = child[cur][1];
        clear(cur);
        maintain(root);
    }
    /**
     * @brief 获取 x 节点对应的权值
     *
     * @param x 欲获取权值的节点
     * @return 获取到的节点的权值
     */
    int getValue(int x)
    {
        return value[x];
    }
};
int main()
{
    Splay tree;
    int n,opt,x;
    cin>>n;
    for(;n;--n){
        cin>>opt>>x;
        if(opt==1)tree.ins(x);
        else if(opt==2)
        else if(opt==3)cout<<tree.rk(x)<<"\n";
        else if(opt==4)cout<<tree.kth(x)<<"\n";
        else if(opt==5)tree.ins(x),cout<<tree.valGet(tree.pre())<<"\n",tree.del(x);
        else if(opt==6)tree.ins(x),cout<<tree.valGet(tree.nxt())<<"\n",tree.del(x);
    }
    return 0;
}