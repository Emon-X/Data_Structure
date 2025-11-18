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

vector<vector<ll>>g;
vector<ll>low, tin;
vector<bool>vis;
vector<pair<ll, ll>>ans;
bool bridgeFind;
ll timer;

void dfs(ll u, ll par = -1) {

    timer++;
    low[u] = tin[u] = timer;
    vis[u] = true;
    for (auto v : g[u]) {
        if (v == par) continue;

        if (!vis[v]) {
            ans.pb({ u,v });
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] > tin[u]) {
                //bidge found
                bridgeFind = true;
            }
        }
        else if (tin[v] < tin[u]) {

            ans.pb({ u,v });
            low[u] = min(low[u], tin[v]);
        }
    }
}

void domain_expension() {
    ll n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0;i < m;i++) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    low.assign(n + 1, -1);
    tin.assign(n + 1, -1);
    vis.assign(n + 1, false);

    bridgeFind = false;
    timer = 0;

    dfs(1);

    if (bridgeFind or ans.size()!=m) {
        cout << "IMPOSSIBLE"<< endl;
        return;
    }
    for (auto [u, v] : ans) cout << u << " " << v << endl;

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