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
#define INF 1e18
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Edge {
    ll u, v, w;
};

vector<ll> find_negative_cycle(ll n, const vector<Edge>& edges) {
    vector<ll> dist(n + 1, 0), parent(n + 1, -1);
    ll x = -1;

    // Relax edges n times (detect cycle in nth iteration)
    for (ll i = 1; i <= n; i++) {
        x = -1;
        for (auto &e : edges) {
            if (dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = max((ll)(-INF), dist[e.u] + e.w);
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }

    if (x == -1) return {}; // no negative cycle

    ll y = x;
    for (int i = 0; i < n; i++) y = parent[y]; // go inside the cycle

    vector<ll> cycle;
    for (ll cur = y;; cur = parent[cur]) {
        cycle.pb(cur);
        if (cur == y && cycle.size() > 1) break;
    }
    reverse(all(cycle));
    return cycle;
}

void domain_expension() {
    ll n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    vector<ll> cycle = find_negative_cycle(n, edges);

    if (cycle.empty()) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (auto u : cycle) cout << u << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        domain_expension();
    return 0;
}
