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
    vector<ll> p, dist;
    DSU(ll n) {
        p.resize(n);
        dist.assign(n, 0);
        iota(all(p), 0);
    }
    ll find(ll x) {
        if(p[x] == x) return x;
        ll par = p[x];
        ll root = find(par);
        dist[x] += dist[par];
        p[x] = root;
        return p[x];
    }
    void unite(ll a, ll b) {
        ll ra = find(a);
        ll rb = find(b);
        if (ra != rb) {
            p[ra] = rb;
            dist[ra] = dist[a] + 1;
        }
    }
    bool same(ll a, ll b) { return find(a) == find(b); }
    ll rank(ll a) {
        find(a);
        return dist[a];
    }
};

void domain_expension()
{
    ll n,m;
    cin >> n >> m;

    DSU d(n+1);

    for(int i=1;i<=m;i++){
        ll t,u,v;
        cin >> t;
        if(t==1){
            cin >> u >> v;
            d.unite(u,v);
        }
        else{
            cin >> u;
            cout << d.rank(u)<<endl;
        }
    }
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