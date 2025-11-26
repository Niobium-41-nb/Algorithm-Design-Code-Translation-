#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct qj{
    int x,y,val;
};

void solve() {
    int n,m;
    cin >> n >> m;
    int x1,y1,x2,y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    vector<vector<int>>arr(n,vector<int>(n,0));
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> arr[i][j];
        }
    }
    queue<qj>q;
    q.push({x1,y1,0});
    while(!q.empty()){
        auto a = q.front();
        if(a.x == x2 && a.y == y2){
            cout << a.val+1 << endl;
            return;
        }
        q.pop();
        for(int k = 0;k < 4;k++){
            int nx = a.x+dx[k];
            int ny = a.y+dy[k];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] == 0){
                q.push({nx,ny,a.val+1});
            }
        }
    }

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