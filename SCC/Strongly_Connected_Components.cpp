#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int N = 500005;
vector<ll> g[N], gr[N];
vector<ll> v, cmp;
vector<bool> vis;

void dfs1(ll u) {
    vis[u] = true;
    for (auto c : g[u])
        if (!vis[c]) dfs1(c);
    v.pb(u);
}

void dfs2(ll u) {
    vis[u] = true;
    cmp.pb(u);
    for (auto c : gr[u])
        if (!vis[c]) dfs2(c);
}

void domain_expension() {
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        g[i].clear();
        gr[i].clear();
    }

    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        gr[v].pb(u);
    }

    vis.assign(n + 1, false);
    v.clear();
    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs1(i);


    vis.assign(n + 1, false);
    vector<vector<ll>> res;

    reverse(all(v));
    for (auto node : v) {
        if (!vis[node]) {
            cmp.clear();
            dfs2(node);
            res.pb(cmp);
        }
    }
    cout << res.size() << "\n";
    for (auto& comp : res) {
        cout << comp.size() << " ";
        for (auto x : comp) cout << x << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        domain_expension();
    return 0;
}
