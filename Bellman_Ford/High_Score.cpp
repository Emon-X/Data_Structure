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
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
bool ok;
vector<ll> bellman_ford(ll n, ll src, const vector<tuple<ll,ll,ll>>& g) {
 
    vector<ll> d(n + 1, -1e18), p(n + 1, -1);
    d[src] = 0;
    ll x = -1;
 
    
    d[1] = 0LL;
    for (int k = 1; k <= n - 1; k++) {
        for (auto &[u, v, w] : g) {
            if (d[u] != -1e18 && d[u] + w > d[v]) {
                d[v] = d[u] + w;
            }
        }
    }
 
    vector<bool> negative(n + 1, false);
    for (int k = 1; k <= n; k++) {
        for (auto &[u, v, w] : g) {
            if (d[u] != -1e18 && d[u] + w > d[v]) {
                d[v] = d[u] + w;
                negative[v] = true;
            }
            if (negative[u]) {
                negative[v] = true;
            }
        }
    }
    if(negative[n]){
        ok = true;
    }
 
    // if (x != -1) {
    //     ll y = x;
    //     for (int i = 0; i < n; i++) y = parent[y]; // reach cycle
 
    //     vector<ll> cycle;
    //     for (ll cur = y;; cur = parent[cur]) {
    //         cycle.push_back(cur);
    //         if (cur == y && cycle.size() > 1) break;
    //     }
    //     reverse(cycle.begin(), cycle.end());
 
    //     // cout << "Negative cycle detected: ";
    //     // for (ll v : cycle) cout << v << " ";
    //     // cout << endl;
   // }
 
    return d;
}
 
void domain_expension()
{
    ll n,m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll>>g;
    for(ll i = 0;i<m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        g.pb({u,v,w});
    }
    ok = false;
    vector<ll>dist = bellman_ford(n,1LL,g);
 
    if(ok){
        cout << -1 << endl;
        return;
    }
    cout << dist[n] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
        domain_expension();
    return 0;
}