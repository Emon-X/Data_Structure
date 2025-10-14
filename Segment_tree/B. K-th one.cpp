#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct segtree{
    ll sz;
    vector<ll>sums;
    void init(ll n){
        sz = 1;
        while(sz < n) sz *= 2;
        sums.assign(2*sz, 0LL);
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
    void update(ll i,ll v){
        update(i,v,0,0,sz);
    }
    // k-th one
    ll query(ll x,ll lx,ll rx,ll k){
        
        if(k > sums[x]) return -1;
    
        if(rx - lx == 1) return lx;
        ll m = lx + (rx - lx) / 2;
    
        if(sums[2*x+1] >= k) return query(2*x+1, lx, m, k);
        else return query(2*x+2, m, rx, k - sums[2*x+1]);
    }

    ll query(ll k){
        return query(0,0,sz,k);
    }

};

void domain_expension()
{
    ll n,q;
    cin >> n >> q;
    segtree st;
    st.init(n);
    vector<ll>s(n);
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        st.update(i,x);
        s[i] = x;
    }
    //for(int i = 0;i<2*st.sz;i++) cout << st.sums[i] << " ";cout<<endl;
    while(q--){
        ll t;
        cin >> t;
        if(t==1){
            ll i;
            cin >> i;
            s[i]^=1;
            st.update(i,s[i]);
        }
        else{
            ll k;
            cin >> k;
            cout << st.query(k+1) << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}