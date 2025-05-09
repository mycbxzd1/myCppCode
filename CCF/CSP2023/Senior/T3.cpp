#include <bits/stdc++.h>
using namespace std;
struct TypeInfo
{
    string name;                          // 类型名
    size_t size = 0;                      // 对齐后大小
    size_t align = 0;                     // 对齐字节
    size_t raw = 0;                       // 未对齐的“真实”大小
    vector<pair<size_t, string>> members; // 成员：(类型下标, 成员名)
    size_t align_up(size_t addr) const
    {
        size_t mask = align - 1;
        return (addr + mask) & ~mask;
    }
    void calc_layout(const vector<TypeInfo> &all)
    {
        size = align = raw = 0;
        size_t cursor = 0;
        for (auto [tid, _] : members)
        {
            const TypeInfo &child = all[tid];
            align = max(align, child.align);
            cursor = (cursor + child.align - 1) / child.align * child.align;
            cursor += child.size;
        }
        raw = cursor;
        size = (cursor + align - 1) / align * align;
    }
    bool is_primitive() const { return members.empty(); }
};
struct Object
{
    size_t tid;  // 类型下标
    string name; // 元素名
};

static vector<TypeInfo> types;
static unordered_map<string, size_t> id;
static vector<Object> objs;
static size_t cur_addr = 0;
size_t align_up(size_t addr, size_t align)
{
    size_t mask = align - 1;
    return (addr + mask) & ~mask;
}
vector<string> split_path(const string &s)
{
    vector<string> res;
    string buf;
    for (char c : s)
    {
        if (c == '.')
        {
            res.push_back(buf);
            buf.clear();
        }
        else
            buf.push_back(c);
    }
    res.push_back(buf);
    return res;
}
pair<bool, size_t> query_path(const string &path)
{
    auto segs = split_path(path);
    if (segs.empty())
        return {false, 0};
    size_t addr = 0;
    size_t tid = numeric_limits<size_t>::max();
    bool found = false;

    for (const auto &[otid, oname] : objs)
    {
        const TypeInfo &tp = types[otid];
        addr = tp.align_up(addr);
        if (oname == segs[0])
        {
            tid = otid;
            found = true;
            break;
        }
        addr += tp.size;
    }
    if (!found)
        return {false, 0};
    for (size_t i = 1; i < segs.size(); ++i)
    {
        const auto &owner = types[tid];
        bool ok = false;
        for (const auto &[cid, mname] : owner.members)
        {
            const TypeInfo &child = types[cid];
            addr = child.align_up(addr);
            if (mname == segs[i])
            {
                tid = cid;
                ok = true;
                break;
            }
            addr += child.size;
        }
        if (!ok)
            return {false, 0};
    }
    return {true, addr};
}
string query_addr(size_t addr)
{
    if (addr >= cur_addr)
        return "ERR";
    size_t pos = 0;
    string path;
    const TypeInfo *tp;
    for (const auto &[tid, oname] : objs)
    {
        tp = &types[tid];
        pos = tp->align_up(pos);
        if (addr < pos)
            return "ERR";
        if (addr < pos + tp->size)
        {
            path = oname;
            break;
        }
        pos += tp->size;
    }
    while (!tp->is_primitive())
    {
        bool enter = false;
        for (const auto &[cid, mname] : tp->members)
        {
            const TypeInfo &child = types[cid];
            pos = child.align_up(pos);
            if (addr < pos)
                return "ERR";
            if (addr < pos + child.size)
            {
                path += '.';
                path += mname;
                tp = &child;
                enter = true;
                break;
            }
            pos += child.size;
        }
        if (!enter)
            return "ERR";
    }
    if (addr < pos + tp->raw)
        return path;
    return "ERR";
}
int main()
{
    // freopen("struct.in", "r", stdin);
    // freopen("struct.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    auto add_base = [&](const string &name, size_t sz)
    {
        TypeInfo t;
        t.name = name;
        t.size = t.align = t.raw = sz;
        id[name] = types.size();
        types.push_back(move(t));
    };
    add_base("byte", 1);
    add_base("short", 2);
    add_base("int", 4);
    add_base("long", 8);
    int n;
    cin >> n;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string type_name;
            int k;
            cin >> type_name >> k;
            TypeInfo t;
            t.name = type_name;
            t.members.resize(k);
            for (int i = 0; i < k; ++i)
            {
                string mem_type, mem_name;
                cin >> mem_type >> mem_name;
                t.members[i] = {id[mem_type], mem_name};
            }
            t.calc_layout(types);
            id[type_name] = types.size();
            types.push_back(std::move(t));
            cout << types.back().size << ' ' << types.back().align << '\n';
        }
        else if (op == 2)
        {
            string type_name, obj_name;
            cin >> type_name >> obj_name;
            size_t tid = id[type_name];
            const TypeInfo &tp = types[tid];
            cur_addr = tp.align_up(cur_addr);
            cout << cur_addr << '\n';
            objs.push_back({tid, obj_name});
            cur_addr += tp.size;
        }
        else if (op == 3)
        {
            string path;
            cin >> path;
            auto [ok, addr] = query_path(path);
            if (ok)
                cout << addr << '\n';
            else
                cout << "ERR\n";
        }
        else if (op == 4)
        {
            size_t addr;
            cin >> addr;
            cout << query_addr(addr) << '\n';
        }
    }
    return 0;
}
