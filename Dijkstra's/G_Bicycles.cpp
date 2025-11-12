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

void domain_expension() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>>g(n + 1);
    for (int i = 0;i < m;i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].pb({ v,w });
        g[v].pb({ u,w });
    }
    vector<ll>cost(n + 1);
    for (int i = 1;i <= n;i++) cin >> cost[i];

    using pii = tuple<ll, ll, ll>;
    priority_queue<pii, vector<pii>, greater<pii>>p;
    vector<unordered_map<ll, ll>> best(n + 1);
    best[1][cost[1]] = 0;

    p.push({ 0,1,cost[1] });

    while (p.size() > 0) {
       auto [wi, u, curr_bike] = p.top();
        p.pop();

        auto it = best[u].find(curr_bike);
        if (it == best[u].end() || it->second < wi) continue;

        if (u == n) {
            cout << wi << endl;
            return;
        }
        if (curr_bike > cost[u]) {
            if (best[u].find(cost[u]) == best[u].end() || best[u][cost[u]] > wi) {
                best[u][cost[u]] = wi;
                p.push({ wi, u, cost[u] });
            }
        }
        for (auto [v, w] : g[u]) {
            ll nwi = wi + w * curr_bike;

            auto &it2 = best[v];

            if (!it2.count(curr_bike) or it2[curr_bike] > nwi) {
                it2[curr_bike] = nwi;
                p.push({ nwi,v,curr_bike });
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        domain_expension();
    return 0;
}