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

struct SegmentData {
    ll mx1, mx2, freq1, freq2;
    SegmentData(ll v) {
        mx1 = v;
        mx2 = LLONG_MIN;
        freq1 = (v == 0 ? 0 : 1);
        freq2 = 0;
    }
};
ll sz;
vector<SegmentData>sums;

SegmentData combine(SegmentData a, SegmentData b) {
    SegmentData res(0);

    vector<ll> vals = {a.mx1, a.mx2, b.mx1, b.mx2};
    sort(rall(vals));
    vals.erase(unique(all(vals)), vals.end());

    res.mx1 = vals[0];
    res.mx2 = (vals.size() > 1 ? vals[1] : LLONG_MIN);

    // Count frequency of mx1
    res.freq1 = 0;
    if (a.mx1 == res.mx1) res.freq1 += a.freq1;
    if (b.mx1 == res.mx1) res.freq1 += b.freq1;

    // Count frequency of mx2
    res.freq2 = 0;
    if (a.mx1 == res.mx2) res.freq2 += a.freq1;
    if (a.mx2 == res.mx2) res.freq2 += a.freq2;
    if (b.mx1 == res.mx2) res.freq2 += b.freq1;
    if (b.mx2 == res.mx2) res.freq2 += b.freq2;

    return res;
}

void update(ll i, ll v, ll x, ll lx, ll rx) {
    if (rx - lx == 1) {
        sums[x] = SegmentData(v);
        return;
    }
    ll m = lx + (rx - lx) / 2;
    if (i < m)
        update(i, v, 2 * x + 1, lx, m);
    else
        update(i, v, 2 * x + 2, m, rx);

    sums[x] = combine(sums[2 * x + 1], sums[2 * x + 2]);
}
void update(ll i, ll v) {
    update(i, v, 0, 0, sz);
}

SegmentData Query(ll l, ll r, ll x, ll lx, ll rx) {
    if (rx <= l || lx >= r)
        return SegmentData(0);
    if (lx >= l && rx <= r)
        return sums[x];

    ll m = lx + (rx - lx) / 2;
    SegmentData left = Query(l, r, 2 * x + 1, lx, m);
    SegmentData right = Query(l, r, 2 * x + 2, m, rx);

    return combine(left, right);
};

SegmentData Query(ll l, ll r) {
    return Query(l, r, 0, 0, sz);
}

void domain_expension() {
    ll n, q;
    cin >> n >> q;

    sz = 1;
    while (sz < n)
        sz *= 2;

    sums.assign(2 * sz + 1, SegmentData(0));

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        update(i, x);
    }

    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll i, v;
            cin >> i >> v;
            i--;
            update(i, v);
        }
        else {
            ll l, r;
            cin >> l >> r;
            l--;
            SegmentData res = Query(l, r);
            //cout << res.mx1 << ' ' << res.mx2 << " " << res.freq1 << " " << res.freq2 << endl;
            cout << res.freq2 << endl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    domain_expension();
    return 0;
}