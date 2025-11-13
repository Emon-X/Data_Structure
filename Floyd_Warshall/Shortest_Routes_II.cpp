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
    ll n,m,q;
    cin >> n >> m >> q;

    vector<vector<ll>>dist(n+1,vector<ll>(n+1,LLONG_MAX));
    for(int i = 0;i<m;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[b][a],c);
    }

    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(dist[i][k]<LLONG_MAX && dist[k][j]<LLONG_MAX){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    while(q--){
        ll i,j;
        cin >> i >> j;
        if(i==j){
            cout << 0 << endl;
            continue;
        }
        cout << (dist[i][j] == LLONG_MAX ? -1 : dist[i][j]) << endl;
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