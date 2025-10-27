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
    string s;
    cin >> s;
    ll q;
    cin >> q;

    string r = s;

    vector<pair<ll,ll>>v;
    for(int i=0;i<q;i++){
        ll t,ind;
        cin >> t >> ind;
        v.pb({t,ind});
        if(t==2) s[ind] = '#';
    }
    ll n = s.size();
    DSU d(n+1);

    for(ll i=0;i<s.size()-1;i++){

        if(s[i]=='#') continue;
        if(s[i]==s[i+1]){
            d.unite(i,i+1);
        }
    }
    //cout << d.size(1) << endl;

    vector<ll>res;
    for(int i=q-1;i>=0;i--){
        ll t = v[i].first, ind = v[i].second;

        char ch = r[ind];
        if(t==2){
            s[ind] = ch;
            if(ind+1<n && ch==s[ind+1]) d.unite(ind,ind+1);
            if(ind-1>=0 && ch==s[ind-1]) d.unite(ind-1,ind);
        }
        else{
            res.pb(d.size(ind));
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
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case " << i << ":"<<endl;
        domain_expension();
    }
    return 0;
}