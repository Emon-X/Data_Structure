#include<bits/stdc++.h>
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

struct segtree{
    ll sz;
    vector<ll>sums;
    void init(ll n)
    {
        sz = 1;
        while(sz<n) sz*=2;
        sums.assign(sz*2,0LL);
    }
    void update(ll i,ll v,ll x,ll lx,ll rx){
        if(rx-lx==1){
            sums[x] = v;
            return;
        }
        ll m = lx + (rx-lx)/2;
        if(i<m) update(i,v,2*x+1,lx,m);
        else update(i,v,2*x+2,m,rx);
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }
    void update(ll i,ll v)
    {
        update(i,v,0,0,sz);
    }
    ll query(ll l,ll r, ll x,ll lx,ll rx)
    {
        if(l>= rx or r<=lx) return 0;
        if(lx>=l && rx<=r) return sums[x];

        ll m = lx + (rx - lx)/2;

        return (query(l,r,2*x+1,lx,m)+query(l,r,2*x+2,m,rx));
    }

    ll query(ll l,ll r){
        return query(l,r,0,0,sz);
    }
};

void domain_expension()
{
    ll n;
    cin >> n;
    vector<pair<ll,ll>> s(n);
    
    for(int i=0;i<n;i++){
        cin >> s[i].first;
        s[i].second = i;
    }

    ll q;
    cin >> q;
    vector<tuple<ll,ll,ll,ll>> v;
    for(int i=0;i<q;i++){
        ll l,r,k;
        cin >> l >> r >> k;
        l--;
        v.pb({k,l,r,i});
    }
    sort(rall(v));
    sort(rall(s));
    segtree st;
    st.init(n);

    vector<ll>res(q);
    ll p = 0;
    for(auto [k,l,r,i]:v){

        while(s[p].first> k){
            st.update(s[p].second,1);
            p++;
        }
        ll x = st.query(l,r);
        res[i] = x;
    }
    for(auto u:res) cout << u << endl;
    
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    domain_expension();
    return 0;
}