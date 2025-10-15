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

struct SegmentData{
    ll sum,prefix,suffix,ans;
};
ll sz;
vector<SegmentData>mx;

SegmentData make_data(ll v)
{
    SegmentData res;
    res.sum = v;
    res.prefix = res.suffix = res.ans = max(0LL,v);
    return res;
}

SegmentData combine(SegmentData l, SegmentData r) {
    SegmentData res;
    res.sum = l.sum + r.sum;
    res.prefix = max(l.prefix, l.sum + r.prefix);
    res.suffix = max(r.suffix, r.sum + l.suffix);
    res.ans = max({l.ans, r.ans, l.suffix + r.prefix});
    return res;
}

void update(ll i,ll v,ll x,ll lx,ll rx){
    if(rx-lx==1){
        mx[x] = make_data(v);
        return;
    }
    ll m = lx + (rx - lx)/2;
    if(i<m) update(i,v,2*x+1,lx,m);
    else update(i,v,2*x+2,m,rx);

    mx[x] = combine(mx[2*x+1],mx[2*x+2]);
}

SegmentData query(ll l,ll r,ll x,ll lx,ll rx){
    if(lx >= r || rx <= l) return make_data(0);
    if(lx >= l && rx <= r) return mx[x];

    ll m = (lx + rx) / 2;
    SegmentData left = query(l, r, 2*x+1, lx, m);
    SegmentData right = query(l, r, 2*x+2, m, rx);
    return combine(left, right);
}

void domain_expension()
{
    ll n, q;
    cin >> n >> q;
    sz = 1;
    while (sz < n) sz <<= 1;
    mx.assign(sz * 3, make_data(0));

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        update(i, x,0,0,sz);
    }
    SegmentData it = query(0, n,0,0,sz);
    cout << it.ans  << endl;
    while (q--)
    {
        ll i, v;
        cin >> i >> v;
        update(i, v,0,0,sz);
        SegmentData it = query(0, n,0,0,sz);
        cout << it.ans << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    domain_expension();
    return 0;
}