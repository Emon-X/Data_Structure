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
    ll n,m,k;
    cin >> n >> m >> k;
    vector<vector<pair<ll,ll>>>g(n+1);
    for(int i = 0;i<m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
    }
    vector<vector<ll>>dist(n+1,vector<ll>(k+1,LLONG_MAX));

    using pi = pair<ll,ll>;
    priority_queue<pi,vector<pi>,greater<pi>>p;
    p.push({0,1});
    dist[1][1] = 0;

    while(p.size()>0)
    {
        auto u = p.top().second;
        ll wi = p.top().first;
        p.pop();

        if(dist[u][k]<wi) continue;

        for(auto [v,w]:g[u]){
            ll nwi = wi + w;

            for(int i = 1;i<=k;i++){
                if(dist[v][i]>nwi){
                    for(int j = k;j>i;j--){
                        dist[v][j] = dist[v][j-1];
                    }
                    dist[v][i] = nwi;
                    p.push({dist[v][i],v});
                    break;
                }
            }
        }
    }
    for(int i = 1;i<=k;i++) cout << dist[n][i] << " ";cout << endl;

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