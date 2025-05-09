#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct TriEvent
{
    ll y;
    int type;
    int id;
};

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> x(n), y(n), m(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> m[i];
        c[i] = x[i] + y[i] + m[i];
    }
    vector<TriEvent> tri_events;
    tri_events.reserve(2 * n);
    for (int i = 0; i < n; i++)
    {
        tri_events.push_back({y[i], 1, i});
        tri_events.push_back({y[i] + m[i], 0, i});
    }
    sort(tri_events.begin(), tri_events.end(),
         [](auto &A, auto &B)
         {
             if (A.y != B.y)
                 return A.y < B.y;
             return A.type < B.type;
         });
    set<pair<ll, int>> active;
    vector<decltype(active.begin())> pos(n);
    using DetachEvt = pair<ll, pair<int, int>>;
    priority_queue<DetachEvt, vector<DetachEvt>, greater<DetachEvt>> pq;
    int p = 0, T = tri_events.size();
    ll curr_y = tri_events[0].y;
    while (p < T && tri_events[p].y == curr_y && tri_events[p].type == 0)
    {
        int id = tri_events[p].id;
        auto it = pos[id];
        auto l = it, r = it;
        bool hasL = false, hasR = false;
        if (it != active.begin())
        {
            hasL = true;
            --l;
        }
        ++r;
        if (r != active.end())
        {
            hasR = true;
        }
        if (hasL && hasR)
        {
            int idL = l->second, idR = r->second;
            ll ydet = c[idL] - x[idR];
            if (ydet > curr_y)
                pq.push({ydet, {idL, idR}});
        }
        active.erase(it);
        p++;
    }
    while (p < T && tri_events[p].y == curr_y && tri_events[p].type == 1)
    {
        int id = tri_events[p].id;
        auto it = active.insert({x[id], id}).first;
        pos[id] = it;
        auto l = it, r = it;
        bool hasL = false, hasR = false;
        if (it != active.begin())
        {
            hasL = true;
            --l;
        }
        ++r;
        if (r != active.end())
        {
            hasR = true;
        }
        if (hasL)
        {
            int idL = l->second;
            ll ydet = c[idL] - x[id];
            if (ydet > curr_y)
                pq.push({ydet, {idL, id}});
        }
        if (hasR)
        {
            int idR = r->second;
            ll ydet = c[id] - x[idR];
            if (ydet > curr_y)
                pq.push({ydet, {id, idR}});
        }
        p++;
    }
    while (!pq.empty() && pq.top().first == curr_y)
        pq.pop();
    auto recompute = [&](double &L_curr, int &comp)
    {
        L_curr = 0.0;
        comp = 0;
        ll prev_end = LLONG_MIN;
        for (auto &pr : active)
        {
            ll xi = pr.first, id = pr.second;
            ll ri = c[id] - curr_y;
            if (ri <= xi)
                continue;
            if (xi < prev_end)
            {
                if (ri > prev_end)
                {
                    L_curr += (double)(ri - prev_end);
                    prev_end = ri;
                }
            }
            else
            {
                L_curr += (double)(ri - xi);
                comp++;
                prev_end = ri;
            }
        }
    };

    double L_curr;
    int comp;
    recompute(L_curr, comp);

    double area = 0.0;

    while (p < T || !pq.empty())
    {
        ll next_tri_y = (p < T ? tri_events[p].y : LLONG_MAX);
        ll next_detach = (!pq.empty() ? pq.top().first : LLONG_MAX);
        ll y_event = min(next_tri_y, next_detach);
        double dy = double(y_event - curr_y);
        if (dy > 0)
        {
            area += L_curr * dy - double(comp) * dy * dy / 2.0;
            curr_y = y_event;
        }
        while (p < T && tri_events[p].y == curr_y && tri_events[p].type == 0)
        {
            int id = tri_events[p].id;
            auto it = pos[id];
            auto l = it, r = it;
            bool hasL = false, hasR = false;
            if (it != active.begin())
            {
                hasL = true;
                --l;
            }
            ++r;
            if (r != active.end())
            {
                hasR = true;
            }
            if (hasL && hasR)
            {
                int idL = l->second, idR = r->second;
                ll ydet = c[idL] - x[idR];
                if (ydet > curr_y)
                    pq.push({ydet, {idL, idR}});
            }
            active.erase(it);
            p++;
        }
        while (p < T && tri_events[p].y == curr_y && tri_events[p].type == 1)
        {
            int id = tri_events[p].id;
            auto it = active.insert({x[id], id}).first;
            pos[id] = it;
            auto l = it, r = it;
            bool hasL = false, hasR = false;
            if (it != active.begin())
            {
                hasL = true;
                --l;
            }
            ++r;
            if (r != active.end())
                hasR = true;
            if (hasL)
            {
                int idL = l->second;
                ll ydet = c[idL] - x[id];
                if (ydet > curr_y)
                    pq.push({ydet, {idL, id}});
            }
            if (hasR)
            {
                int idR = r->second;
                ll ydet = c[id] - x[idR];
                if (ydet > curr_y)
                    pq.push({ydet, {id, idR}});
            }
            p++;
        }
        while (!pq.empty() && pq.top().first == curr_y)
            pq.pop();
        recompute(L_curr, comp);
    }
    cout << fixed << setprecision(1) << area << "\n";
    return 0;
}
