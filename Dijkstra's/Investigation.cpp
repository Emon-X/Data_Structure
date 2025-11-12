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
    vector<vector<pair<ll,ll>>>g(n+1);
    for(int i = 0;i<m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
    }
    
    vector<ll>dist(n+1,-1),path(n+1,0),mn_flight(n+1,-1),mx_flight(n+1,-1);
    using pi = pair<ll,ll>;
    priority_queue<pi,vector<pi>,greater<pi>> p;
 
    p.push({0,1});
    path[1] = 1;
    dist[1] = 0;
    mn_flight[1] = 0;
    mx_flight[1] = 0;

    vector<ll>vis(n+1,-1);


 
    while(p.size()>0)
    {
        ll u = p.top().second;
        ll wi = p.top().first;
        p.pop();
 
        if(vis[u]==1) continue;

        vis[u] = 1;
 
        for(auto [v,w]:g[u]){
            if(dist[v] == -1 or dist[u] + w < dist[v]){

                dist[v] = dist[u] + w;
                path[v] = path[u];
                mn_flight[v] = mn_flight[u] + 1;
                mx_flight[v] = mx_flight[u] + 1;
                p.push({dist[v],v});

            }
            else if(dist[v]==dist[u] + w){
                path[v] = (path[v] + path[u])%mod;
                mn_flight[v] = min(mn_flight[v],mn_flight[u] + 1);
                mx_flight[v] = max(mx_flight[v],mx_flight[u] + 1);
            }
        }
    }
    cout << dist[n] << " " << path[n] << " " << mn_flight[n] << " " << mx_flight[n] << endl;
   
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
    