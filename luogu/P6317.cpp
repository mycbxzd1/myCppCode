#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int id;
    int r, c;
};
struct Step
{
    int id;
    char dir;
};
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<Node> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].r >> a[i].c;
        a[i].id = i + 1;
    }
    vector<Step> ans;
    ans.reserve(2 * n * (n - 1));
    vector<Node *> row;
    row.reserve(n);
    for (auto &t : a)
        row.push_back(&t);
    sort(row.begin(), row.end(),
         [](Node *x, Node *y)
         { return x->r < y->r; });
    vector<int> lRow(n + 1);
    for (int i = 0; i < n; ++i)
        lRow[row[i]->id] = i + 1;
    for (auto *p : row)
    {
        int id = p->id;
        while (p->r > lRow[id])
        {
            --p->r;
            ans.push_back({id, 'U'});
        }
        while (p->r < lRow[id])
        {
            ++p->r;
            ans.push_back({id, 'D'});
        }
    }
    vector<Node *> col;
    col.reserve(n);
    for (auto &t : a)
        col.push_back(&t);
    sort(col.begin(), col.end(),
         [](Node *x, Node *y)
         { return x->c < y->c; });
    vector<int> lCol(n + 1);
    for (int j = 0; j < n; ++j)
        lCol[col[j]->id] = j + 1;
    for (auto *p : col)
    {
        int id = p->id;
        while (p->c > lCol[id])
        {
            --p->c;
            ans.push_back({id, 'L'});
        }
        while (p->c < lCol[id])
        {
            ++p->c;
            ans.push_back({id, 'R'});
        }
    }
    cout << ans.size() << '\n';
    for (auto &s : ans)
        cout << s.id << ' ' << s.dir << '\n';
    return 0;
}