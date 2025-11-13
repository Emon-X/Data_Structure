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
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Edge {
    ll a, b, cost;
};

void domain_expension() {
    ll n, m, q, s;
    while (cin >> n >> m >> q >> s) {
        if (n == 0 && m == 0 && q == 0 && s == 0) return;

        vector<Edge> g(m);
        for (int i = 0; i < m; i++) cin >> g[i].a >> g[i].b >> g[i].cost;

        vector<ll> dist(n, LLONG_MAX), p(n, -1);
        dist[s] = 0;
        ll x = -1;

        // Bellman–Ford core
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                if (dist[g[j].a] < LLONG_MAX && dist[g[j].a] + g[j].cost < dist[g[j].b]) {
                    dist[g[j].b] = dist[g[j].a] + g[j].cost;
                    p[g[j].b] = g[j].a;
                }
            }
        }

        // detect negative cycle
        x = -1;
        for (int j = 0; j < m; j++) {
            if (dist[g[j].a] < LLONG_MAX && dist[g[j].a] + g[j].cost < dist[g[j].b]) {
                p[g[j].b] = g[j].a;
                x = g[j].b;
            }
        }

        vector<int> neg(n, 0);
        if (x != -1) {
            // find one vertex inside the cycle
            ll y = x;
            for (int i = 0; i < n; i++) y = p[y];

            // reconstruct cycle path
            vector<int> cyc;
            for (int cur = y;; cur = p[cur]) {
                cyc.pb(cur);
                if (cur == y && cyc.size() > 1) break;
            }
            reverse(all(cyc));

            cout << "Detected negative cycle path: ";
            for (int v : cyc) cout << v << " ";
            cout << endl;

            // mark all vertices reachable from the cycle as affected
            vector<vector<int>> adj(n);
            for (auto& e : g) adj[e.a].pb(e.b);
            queue<int> qq;
            vector<int> vis(n, 0);
            for (int v : cyc) {
                neg[v] = 1;
                qq.push(v);
            }
            while (!qq.empty()) {
                int u = qq.front(); qq.pop();
                for (int v : adj[u]) {
                    if (!neg[v]) {
                        neg[v] = 1;
                        qq.push(v);
                    }
                }
            }
        }
        else {
            cout << "No negative cycle detected" << endl;
        }

        // Answer queries
        while (q--) {
            ll u; cin >> u;
            if (neg[u]) cout << "-Infinity" << endl;
            else if (dist[u] == LLONG_MAX) cout << "Impossible" << endl;
            else cout << dist[u] << endl;
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    domain_expension();
    return 0;
}
