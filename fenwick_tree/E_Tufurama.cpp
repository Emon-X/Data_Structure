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
    ll sz;
    vector<ll>bit;
    fenwick_tree(ll n){
        sz = n + 2;
        bit.assign(sz,0LL);
    }
    void update(ll i,ll v){
        for(;i<sz;i+=(i&-i)) bit[i]+=v;
    }
    ll sum(ll r){
        ll ans = 0;
        for(;r>0;r-=(r&-r)) ans+=bit[r];

        return ans;
    }
};

void domain_expension()
{
    ll n;
    cin >> n;
    vector<ll>ind[n+1];
    vector<ll>s(n+1);

    fenwick_tree st(n+1);

    for(int i=1;i<=n;i++){
        cin>> s[i];
        s[i] = min(s[i],n);
        ind[s[i]].pb(i);

        st.update(i,1);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ll x = st.sum(s[i]);
        ans+=x;
        for(auto u:ind[i]) st.update(u,-1);
    }
    for(int i=1;i<=n;i++){
        if(i<=s[i]) ans--;
    }
    cout << ans/2 << endl;
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