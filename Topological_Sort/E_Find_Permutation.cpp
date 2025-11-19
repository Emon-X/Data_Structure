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

void domain_expension()
{
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>>g(n+1);
    vector<ll>indeg(n+1);
    for(int i = 0;i<m;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        indeg[v]++;
    }
    queue<ll>p;
    for(int i = 1;i<=n;i++) if(indeg[i]==0) p.push(i);

    vector<ll>ans;
    
    while(!p.empty()){

        if(p.size()>1){
            cout << "No" << endl;
            return;
        }
        ll u = p.front();
        p.pop();

        ans.pb(u);

        for(auto v:g[u]){
            indeg[v]--;
            if(indeg[v]==0) p.push(v);
        }
    }
    if((ll)ans.size()!=n){
        cout << "No" << endl;
        return;
    }
    ll d = 1;
    vector<ll>res(n);
    for(auto u:ans){
        res[u-1] = d;
        d++;
    }
    cout << "Yes" << endl;
    for(auto u:res) cout << u << " ";cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        domain_expension();
    return 0;
}