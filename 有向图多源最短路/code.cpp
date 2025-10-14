/*
    有向图多源最短路

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
#include <vector>
#define int long long
using namespace std;
const int INF = 1e18;
vector<vector<int>>dp;int n,m;
void debug(){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(dp[i][j] == INF){
                cout << "INF ";
            }else{
                cout << dp[i][j] << ' ';
            }
        }
        cout << endl;
    }
    cout << endl;
}
signed main(){
    cin >> n >> m;
    dp.assign(n+1,vector<int>(n+1,INF));
    for(int i = 1;i <= m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        // 建立 u -> v 的有向边 权重 为 w
        dp[u][v] = w;
    }
    for(int i = 1;i <= n;i++){
        dp[i][i] = 0;
    }
    for(int k = 1;k <= n;k++){
        // debug();
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(dp[i][j] == INF){
                cout << "INF ";
            }else{
                cout << dp[i][j] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}