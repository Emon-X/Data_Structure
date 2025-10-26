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

struct fenwick_tree{
    vector<ll>bit;
    ll sz;
    fenwick_tree(ll n){
        sz = n + 2;
        bit.assign(sz,0LL);
    }
    void update(ll i,ll v){
        for(;i<sz;i+=(i&-i)){
            bit[i]+=v;
        }
    }
    ll sum (ll r){
        ll ans = 0;
        for(;r>0;r-=(r&-r)){
            ans+=bit[r];
        }
        return ans;
    }
    ll range_sum(ll l,ll r){
        return sum(r)-sum(l-1);
    }
};

void domain_expension()
{
    ll n,q;
    cin >> n >> q;
    vector<ll>s(n+1);
    for(int i=1;i<=n;i++) cin >> s[i];

    //cordinate compressed
    vector<ll>cmp = s;
    sort(all(cmp));
    cmp.erase(unique(cmp.begin(),cmp.end()),cmp.end());
    for(auto &x : s) x = lower_bound(all(cmp),x) - cmp.begin();

    vector<tuple<ll,ll,ll>> v;
    for(int i=1;i<=q;i++){
        ll l,r;
        cin >> l >> r;
        v.pb({r,l,i});
    }
    sort(all(v));

    fenwick_tree bit(n+1);
    vector<ll>last(n+1,-1),res(q+1);
    ll curr = 0;
    for(auto [r,l,i]:v){
        while(curr<r){
            
            curr++;
            ll val = s[curr];
            if(last[val]!=-1) bit.update(last[val],-1);
            bit.update(curr,1);
            
            last[val] = curr;
        }
        res[i] = bit.range_sum(l,r);
    }
    for(int i=1;i<=q;i++) cout << res[i] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    ///cin >> t;
    while (t--)
        domain_expension();
    return 0;
}