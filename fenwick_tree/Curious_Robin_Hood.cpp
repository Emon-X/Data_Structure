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

struct fenwick_tree {
    vector<ll>bit;
    ll sz;
    fenwick_tree(ll n) {
        sz = n + 4;
        bit.assign(sz, 0LL);
    }
    void update(ll i, ll v) {
        for (;i <= sz;i += (i & -i)) {
            bit[i] += v;
        }
    }
    ll sum(ll i) {
        ll ans = 0;
        for (;i > 0;i -= (i & -i)) {
            ans += bit[i];
        }
        return ans;
    }
    ll range(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }
};

void domain_expension() {
    ll n, q;
    cin >> n >> q;
    vector<ll>s(n + 1);
    fenwick_tree bit(n + 1);

    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        bit.update(i, s[i]);
    }
    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll r;
            cin >> r;
            r++;
            ll val = bit.range(r,r);
            bit.update(r, -val);
            cout << val << endl;
        }
        else if (t == 2) {
            ll i, v;
            cin >> i >> v;
            i++;
            bit.update(i, v);
        }
        else {
            ll l, r;
            cin >> l >> r;
            l++, r++;
            cout << bit.range(l, r) << endl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1;i <= t;i++) {
        cout << "Case " << i << ":" << endl;
        domain_expension();
    }
    return 0;
}
