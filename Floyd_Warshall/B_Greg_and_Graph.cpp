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
    ll n;
    cin >> n;
    vector<vector<ll>>dist(n+1,vector<ll>(n+1));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> dist[i][j];
        }
    }
    vector<ll>d(n+1);
    for(int i = 1;i<=n;i++) cin >> d[i];

    vector<ll>ans(n+1),vis(n+1,0);

    for(int t=n;t>=1;t--)
    {
        ll k = d[t];
        vis[k] = 1;

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(dist[i][k] + dist[k][j]<dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j]; 
            }
        }
        ll sum = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(vis[i] && vis[j]){
                    sum+=dist[i][j];
                }
            }
        }
        ans[t] = sum;
    }
    for(int i = 1;i<=n;i++) cout << ans[i] << " ";cout << endl;
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