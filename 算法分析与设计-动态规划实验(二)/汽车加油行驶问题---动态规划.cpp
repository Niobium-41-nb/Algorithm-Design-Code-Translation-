#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
/*
给定一个N*N 的方形网格，设其左上角为起点◎，坐标为（1，1），X 轴向右为正，Y 轴向下为正，每个方格边长为1。一辆汽车从起点◎出发驶向右下角终点▲，其坐标为（N， N）。在若干个网格交叉点处，设置了油库，可供汽车在行驶途中加油。汽车在行驶过程中应遵守如下规则：
（1）汽车只能沿网格边行驶，装满油后能行驶K 条网格边。出发时汽车已装满油，在
起点与终点处不设油库。
（2）当汽车行驶经过一条网格边时，若其X 坐标或Y 坐标减小，则应付费用B，否则
免付费用。
（3）汽车在行驶过程中遇油库则应加满油并付加油费用A。
（4）在需要时可在网格点处增设油库，并付增设油库费用C（不含加油费用A）。
（5）(1)～(4) 中的各数N、K、A、B、C 均为正整数。

*/
vector<vector<int>>arr;
vector<vector<vector<int>>>dp;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
struct qj{
    int x;
    int y;
    int s;
    int cost;
};
void solve() {
    int n,k,A,B,C;
    cin >> n >> k >> A >> B >> C;
    arr.assign(n+1,vector<int>(n+1,0));
    dp.assign(n+1,vector<vector<int>>(n+1,vector<int>(k+1,INF)));
    for(int i =1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> arr[i][j];
        }
    }
    dp[1][1][k] = 0;
    
    queue<qj>q;
    q.push({1,1,k,0});
    
    while(!q.empty()){
        qj cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int s = cur.s;
        int cost = cur.cost;
        
        if(cost > dp[x][y][s]) continue;
        
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            
            int new_cost = cost;
            if(dx[i] < 0 || dy[i] < 0){
                new_cost += B;
            }
            
            if(s == 0) continue;
            
            int new_s = s - 1;
            if(arr[nx][ny] == 1){
                new_cost += A;
                new_s = k;
            }
            
            if(new_s == 0 && (nx != n || ny != n)){
                if(arr[nx][ny] == 0){
                    new_cost += A + C;
                    new_s = k;
                }
            }
            
            if(new_cost < dp[nx][ny][new_s]){
                dp[nx][ny][new_s] = new_cost;
                q.push({nx,ny,new_s,new_cost});
            }
        }
    }
    
    int ans = INF;
    for(int i = 0;i <= k;i++){
        ans = min(ans,dp[n][n][i]);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// by vanadium-23