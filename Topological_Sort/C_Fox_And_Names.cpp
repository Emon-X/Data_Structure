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
    ll n;
    cin >> n;
    vector<string>s(n);
    for (int i = 0;i < n;i++) cin >> s[i];

    vector<vector<ll>>g(26);
    vector<ll>indeg(26);

    for (int i = 1;i < n;i++) {

        string a = s[i - 1], b = s[i];

        ll mn = min(a.size(), b.size());
        ll j = 0;
        while (j < mn && a[j] == b[j]) j++;

        if (j == mn) {
            if (a.size() > b.size()) {
                cout << "Impossible" << endl;
                return;
            }
            continue;
        }

        ll u = s[i - 1][j] - 'a';
        ll v = s[i][j] - 'a';
        g[u].pb(v), indeg[v]++;

    }
    vector<ll>ans;

    priority_queue<ll, vector<ll>, greater<ll>>p;
    for (int i = 0;i < 26;i++) if (indeg[i] == 0) p.push(i);

    while (!p.empty()) {
        ll u = p.top();
        p.pop();
        ans.pb(u);

        for (auto v : g[u]) {
            indeg[v]--;
            if (indeg[v] == 0) p.push(v);
        }
    }
    if ((ll)ans.size() != 26) {
        cout << "Impossible" << endl;
        return;
    }
    for (auto u : ans) cout << char(u + 97);cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    domain_expension();
    return 0;
}