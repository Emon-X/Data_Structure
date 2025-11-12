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

vector<ll> dijkstra(ll n, ll src, const vector<vector<pair<ll,ll>>>& adj) {

    vector<ll> dist(n + 1, LLONG_MAX);
    dist[src] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v,w] : adj[u]) {
          
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

void domain_expension()
{
    ll n,m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>>g1(n+1),g2(n+1);
    vector<tuple<ll,ll,ll>> edges;
    edges.reserve(m);
    for(int i = 0;i<m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        edges.emplace_back(u,v,w);
        g1[u].pb({v,w});
        g2[v].pb({u,w});
    }
    vector<ll>d1 = dijkstra(n,1,g1);
    vector<ll>d2 = dijkstra(n,n,g2);
    ll ans = LLONG_MAX;
    for (auto [a,b,w] : edges) {
        if (d1[a] == LLONG_MAX || d2[b] == LLONG_MAX) continue;
        
        ans = min(ans, d1[a] + d2[b] + (w / 2));
    }
    cout << ans << endl;
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