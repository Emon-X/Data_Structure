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

bool ok = false;

void dfs(ll u,const vector<ll>g[],vector<bool>&vis,vector<bool>&inStack,vector<ll>&res)
{
    vis[u] = true;
    inStack[u] = true;
    for(auto v:g[u]){
        if(!vis[v]){
            dfs(v,g,vis,inStack,res);
            if(ok) return;
        }
        else if(inStack[v]){
            ok = true;
            return;
        }
    }
    inStack[u] = false;
    res.pb(u);
}

void domain_expension()
{
    ll n,m;
    cin >> n >> m;
    vector<ll>g[n+1];
    for(int i = 0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        g[a].pb(b);
    }
    vector<bool>vis(n+1,false);
    vector<bool>inStack(n+1,false);
    vector<ll>res;

    for(int i = 1;i<=n;i++) if(!vis[i]) dfs(i,g,vis,inStack,res);

    if(ok) cout << "IMPOSSIBLE" << endl;
    else{
        reverse(all(res));
        for(auto u:res) cout << u << " ";cout << endl;
    }
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