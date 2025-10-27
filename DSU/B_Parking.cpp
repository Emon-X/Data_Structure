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

struct DSU {
    vector<ll> p, sz;
    DSU(ll n) {
        p.resize(n + 5);
        sz.assign(n + 5, 1);
        for (int i = 1;i <= n;i++) p[i] = i;
    }
    ll find(ll x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void unite(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            p[b] = a;
            sz[a] += sz[b];
        }
    }
    bool same(ll a, ll b) { return find(a) == find(b); }
    ll size(ll a) { return sz[find(a)]; }
};

void domain_expension() {
    ll n;
    cin >> n;
    DSU d(n + 1);
    vector<ll>res(n + 1),vis(n+1,0);
    set<ll>st;
    for(int i=1;i<=n;i++) st.insert(i);

    for (int i = 1;i <= n;i++) {
        ll x;
        cin >> x;
        ll sz = d.size(x);
        if (sz == 1) {
            res[i] = x;
            d.unite(0, x);
            st.erase(x);
        }
        else {
    
            auto it = st.lower_bound(x+1);
            if(it==st.end()) it = st.begin();

            x = *it;
            res[i] = x;
            d.unite(0 , x);
            vis[x] = 1;
            st.erase(x);
        }
    }
    for (int i = 1;i <= n;i++) cout << res[i] << " ";cout << endl;
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