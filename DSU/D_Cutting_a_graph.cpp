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

struct DSU {
    vector<ll> p, sz;
    DSU(ll n) {
        p.resize(n);
        sz.assign(n, 1);
        iota(all(p), 0);
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

void domain_expension()
{
    ll n,m,q;
    cin >> n >> m >> q;
    for(int i=0;i<m;i++){
        ll u,v;
        cin >> u >> v;
    }
    vector<tuple<string,ll,ll>> s;
    for(int i=0;i<q;i++){
        string r;
        ll u,v;
        cin >> r >> u >> v;
        s.push_back({r,u,v});
    }

    DSU d(n+1);

    vector<string>res;
    for(int i=q-1;i>=0;i--){
        string r = get<0>(s[i]);
        ll u = get<1>(s[i]);
        ll v = get<2>(s[i]);

        if(r=="ask"){
            if(d.same(u,v)){
                res.pb("YES");
            }
            else{
                res.pb("NO");
            }
        }
        else{
            d.unite(u,v);
        }
    }
    reverse(all(res));
    for(auto u:res) cout << u << endl;
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