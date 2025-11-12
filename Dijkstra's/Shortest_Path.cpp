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
    ll n,m,s,t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<ll,ll>>>g(n+1);
    for(int i = 0;i<m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
    }
    using pi = pair<ll,ll>;
    priority_queue<pi,vector<pi>,greater<pi>>p;
    vector<ll>dist(n+1,LLONG_MAX),par(n+1,-1);
    vector<bool>vis(n+1,false);

    p.push({0,s});
    dist[s] = 0;

    while(p.size()>0)
    {
        ll u = p.top().second;
        ll weight = p.top().first;
        p.pop();

        if(weight>dist[u]) continue;

        for(auto [v,w]:g[u]){
            
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u] + w;
                par[v] = u;
                p.push({dist[v],v});
            }
        }
    }
    if(dist[t]==LLONG_MAX){
        cout << "-1" << endl;
        return;
    }

    vector<ll>path;
    for(int u = t;u!=-1;u=par[u]){
        path.pb(u);
    }
    reverse(all(path));

    cout <<dist[t] << " "<<path.size() - 1 << endl;
    for(int i = 0;i<path.size()-1;i++){
        cout << path[i] << " " << path[i+1] << endl;
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