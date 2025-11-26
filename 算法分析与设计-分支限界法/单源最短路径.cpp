#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int dist[N];
struct mycom{
    bool operator()(const int a,const int b) const {
        return dist[a] > dist[b];
    }
};

void solve() {
    int n,m;
    cin >> n >> m;
    map<int,int>mp;
    for(int i = 1;i <= n;i++){
        int tmp;cin >> tmp;
        mp[tmp] = i;
        dist[i] = INF;
    }
    vector<vector<pair<int,int>>>g(n+1);
    for(int i = 1;i <= m;i++){
        int from,to,w;
        cin >> from >> to >> w;
        g[from].push_back({to,w});
    }
    dist[1] = 0;
    priority_queue<int,vector<int>,mycom>pq;
    for(int i = 1;i <= n;i++){
        pq.push(i);
    }
    while(!pq.empty()){
        int a = pq.top();
        // cout << "a = " << a << endl;
        pq.pop();
        for(auto p : g[a]){
            int to = p.first;
            int w = p.second;
            dist[to] = min(dist[to],dist[a]+w);
        }
    }
    for(int i = 2;i <= n;i++){
        cout << dist[i] << endl;
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