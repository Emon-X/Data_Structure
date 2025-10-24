#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define endl "\n"

template <typename T>
struct fenwick {
    vector<T> bit;
    ll sz;
    fenwick(ll n) { sz = n + 2; bit.assign(sz, 0); }
    void update(ll i, T v) { for (; i < sz; i += i & -i) bit[i] += v; }
    T sum(ll i) { T s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
};

void domain_expension() {
    ll n; cin >> n;
    vector<pair<char, vector<ll>>> ops;
    vector<ll> coords;
    vector<pair<ll, ll>> segs(1);

    for (int i = 0; i < n; i++) {
        char ch; cin >> ch;
        if (ch == 'D') {
            ll L, R; cin >> L >> R;
            ops.pb({ ch, {L, R} });
            coords.pb(L); coords.pb(R);
        }
        else if (ch == 'C') {
            ll id; cin >> id;
            ops.pb({ ch, {id} });
        }
        else {
            ll L, R; cin >> L >> R;
            ops.pb({ ch, {L, R} });
            coords.pb(L); coords.pb(R);
        }
    }

    sort(all(coords));
    coords.erase(unique(all(coords)), coords.end());
    auto compress = [&](ll x) {
        return (ll)(lower_bound(all(coords), x) - coords.begin() + 1);
        };

    ll m = coords.size();
    fenwick<ll> bitL(m), bitR(m);

    for (auto& op : ops) {
        char ch = op.first;
        if (ch == 'D') {
            ll L = compress(op.second[0]);
            ll R = compress(op.second[1]);
            segs.pb({ L, R });
            bitL.update(L, 1);
            bitR.update(R, 1);
        }
        else if (ch == 'C') {
            ll id = op.second[0];
            auto [L, R] = segs[id];
            bitL.update(L, -1);
            bitR.update(R, -1);
        }
        else { // Q L R
            ll L = compress(op.second[0]);
            ll R = compress(op.second[1]);
            
            cout << bitL.sum(R) - bitR.sum(L-1) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    domain_expension();
    return 0;
}
