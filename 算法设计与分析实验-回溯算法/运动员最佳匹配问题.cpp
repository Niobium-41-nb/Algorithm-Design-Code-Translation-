#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<int>vis(N+1,false);
vector<int>arr(N+1,0);
vector<vector<int>>P;
vector<vector<int>>Q;
int ans = 0;
int n;
void dfs(int dep,int i){
    if(dep == n){
        int sum = 0;
        for(int i = 1;i <= n;i++){
            // cout << arr[i] << ' ';
            sum += P[i][arr[i]]*Q[arr[i]][i];
        }
        // cout << endl;
        if(sum < ans){
            return;
        }
        // cout << "sum = " << sum << endl;
        ans = max(ans,sum);
        return;
    }
    for(int i = 1;i <= n;i++){
        if(vis[i] == false){
            vis[i] = true;
            arr[dep+1] = i;
            dfs(dep+1,i);
            vis[i] = false;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    P.assign(n+1,vector<int>(n+1,0));
    Q.assign(n+1,vector<int>(n+1,0));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> P[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> Q[i][j];
        }
    }
    for(int i =1;i <= n;i++){
        arr[1]=i;
        vis[i] = true;
        dfs(1,i);
        vis[i]=false;
    }
    cout << ans << endl;
    
    return 0;
}

// by vanadium-23