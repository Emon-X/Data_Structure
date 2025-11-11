#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define pp pop_back()
#define mod 1000000007
#define endl "\n"
#define N 200005
ll dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
ll dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<ll>g[N], gr[N];
vector<bool>vis;
vector<ll>v, cmp;

void dfs1(ll node) {
    vis[node] = true;
    for (auto u : g[node]) {
        if (!vis[u]) dfs1(u);
    }
    v.pb(node);
}

void dfs2(ll node) {
    vis[node] = true;
    cmp.pb(node);
    for (auto u : gr[node]) if (!vis[u]) dfs2(u);
}

void domain_expension() {
    ll n, m;
    cin >> n >> m;

    for (int i = 0;i < m;i++) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        gr[v].pb(u);
    }
    vis.assign(n + 1, false);
    v.clear();

    for (int i = 1;i <= n;i++) {
        if (vis[i]) continue;
        dfs1(i);
    }
    reverse(all(v));

    vis.assign(n + 1, false);
    vector<ll>ind[n + 1];
    ll scc = 0;

    for (auto u : v) {
        if (vis[u]) continue;

        cmp.clear();
        dfs2(u);
        scc++;
        for (auto c : cmp) ind[scc].pb(c);
    }
    if (scc==1) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    cout << ind[2][0] << " " << ind[1][0] << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
        domain_expension();
    return 0;
}