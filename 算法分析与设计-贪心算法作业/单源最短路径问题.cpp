#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

map<int,int>len;

struct Mycom{
    bool operator()(const int a,const int b) const {
        return len[a] > len[b];
    }
};

void solve() {
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        len[i] = INF;
    }
    vector<int>inder(n+1,0);
    vector<vector<pair<int,int>>>g(n+1);
    for(int i =1 ;i <= m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        inder[v]++;
    }
    priority_queue<int,vector<int>,Mycom>pq;
    len[1] = 0;
    // for(int i = 1;i <= n;i++)pq.push(i);
    pq.push(1);
    while(!pq.empty()){
        int a = pq.top();
        // cout << "a = " << a << endl;
        pq.pop();
        for(auto p : g[a]){
            int to = p.first;
            int val = p.second;
            inder[to]--;
            len[to] = min(len[to],len[a]+val);
            // cout << "   len[" << to << "] = " << len[to] << endl;
            if(inder[to]==0){
                pq.push(to);
            }
        }
    }
    for(int i = 2;i <= n;i++){
        cout << len[i] << ' ';
    }
    cout << endl;

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