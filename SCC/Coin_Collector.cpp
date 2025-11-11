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

vector<ll>g[N],gr[N];
vector<ll>v,cmp;
vector<bool>vis;

void dfs1(ll node){
    vis[node] = true;
    for(auto c:g[node]) if(!vis[c]) dfs1(c);

    v.pb(node);
}

void dfs2(ll node){
    vis[node] = true;
    cmp.pb(node);
    for(auto c:gr[node]) if(!vis[c]) dfs2(c);
}

void domain_expension()
{
    ll n,m;
    cin >> n >> m;
    vector<ll>cost(n+1);
    for(int i = 1;i<=n;i++){
        cin >> cost[i];
    }
    for(int i = 1;i<=m;i++){
        ll a,b;
        cin >> a >> b;
        g[a].pb(b);
        gr[b].pb(a);
    }
    vis.assign(n+1,false);
    v.clear();
    for(int i = 1;i<=n;i++){
        if(!vis[i]) dfs1(i);
    }
    vis.assign(n+1,false);
    vector<ll>ind(n+1);

    reverse(all(v));
    vector<ll>sum(n+2);

    ll scc = 0;
    for(auto u:v){
        if(vis[u]) continue;
        cmp.clear();
        dfs2(u);
        scc++;
        ll ss = 0;
        for(auto c:cmp) ind[c] = scc,ss+=cost[c];

        sum[scc] = ss;
    }
    vector<vector<ll>>dag(scc + 1);
    vector<ll>indegree(scc + 1,0);

    for(int i = 1;i<=n;i++){
        for(auto u:g[i]){
            if(ind[u]!=ind[i]){
                dag[ind[i]].pb(ind[u]);
                indegree[ind[u]]++;
            }
        }
    }
   
    queue<ll>p;
    vector<ll>dp(scc + 1);

    for(int i = 1;i<=scc;i++){
        if(indegree[i]==0) p.push(i);
        dp[i] = sum[i];
    }
   
    ll ans = 0;

    while(p.size()>0)
    {
        auto node = p.front();
        p.pop();

        for(auto u:dag[node])
        {
            dp[u] = max(dp[u],dp[node] + sum[u]);
            indegree[u]--;
            if(indegree[u]==0) p.push(u);
        }
        ans = max(ans,dp[node]);
    }
    cout << ans << endl;
    
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