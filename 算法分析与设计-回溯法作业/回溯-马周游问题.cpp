#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

int vis[10][10] = {0};
int dx[8] = {1,1,-1,-1,2,2,-2,-2};
int dy[8] = {2,-2,2,-2,1,-1,1,-1};
int maxstep = 0;
void dfs(int x,int y,int step){
    // cout << "in : (" << x << "," << y << ")\n";
    // cout << "step = " << step << endl;
    
    // if(step > maxstep){
    //     maxstep = step;
    //     for(int i = 1;i <= 8;i++){
    //         for(int j = 1;j <= 8;j++){
    //             cout << vis[i][j] << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    if(step == 64){
        cout << "YES\n";
        return;
    }
    for(int k = 0;k < 8;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(vis[nx][ny]==0 && 1 <= nx && nx <= 8 && 1 <= ny && ny <= 8){
            vis[nx][ny] = 1;
            dfs(nx,ny,step+1);
            vis[nx][ny] = 0;
        }
    }
    

}
void init(){
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            vis[i][j] = 0;
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // for(int i = 1;i <= 8;i++){
    //     for(int j = 1;j <= 8;j++){
    //         vis[i][j]=1;
    //         dfs(i,j,1);
    //         vis[i][j]=0;
    //     }
    // }
    vis[1][1]=1;
    dfs(1,1,1);
    vis[1][1]=0;
    return 0;
}

// by vanadium-23