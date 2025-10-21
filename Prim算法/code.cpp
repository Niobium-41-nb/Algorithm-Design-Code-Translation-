/*
    Prim算法

作者：vanadium-23(Niobium-41-nb)
例题：https://www.luogu.com.cn/problem/P3366
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAXN = 5010; // 最大节点数
const int MAXM = 200010; // 最大边数

struct edge{
    int from, to, val;
    bool operator < (const edge &other) const {
        return val > other.val; 
    }
};

vector<edge> graph[MAXN]; 
int dist[MAXN]; 
bool visited[MAXN]; 

// Prim算法实现，返回最小生成树的总权值
int prim(int n){
    int totalWeight = 0; // 最小生成树的总权值
    int count = 0; // 已加入生成树的节点数
    
    // 初始化距离数组为无穷大
    for(int i = 1; i <= n; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    
    // 优先队列，按边权从小到大排列
    priority_queue<edge> pq;
    
    // 从节点1开始
    dist[1] = 0;
    pq.push({0, 1, 0});
    
    while(!pq.empty() && count < n){
        edge e = pq.top();
        pq.pop();
        
        int u = e.to;
        
        // 如果节点已经加入生成树，跳过
        if(visited[u]) continue;
        
        // 将节点加入生成树
        visited[u] = true;
        totalWeight += e.val;
        count++;
        
        // 更新生成树到其他节点的距离
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].to;
            int w = graph[u][i].val;
            if(!visited[v] && w < dist[v]){
                dist[v] = w;
                pq.push({u, v, w});
            }
        }
    }
    
    // 判断是否存在最小生成树（所有节点都能被访问到）
    if(count != n) return -1;
    return totalWeight;
}

int main(){
    int n, m; // n个节点，m条边
    cin >> n >> m;
    
    // 读取边的信息
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        // 无向图，所以两个方向都要添加
        graph[u].push_back({u, v, w});
        graph[v].push_back({v, u, w});
    }
    
    int result = prim(n);
    
    if(result == -1){
        cout << "orz" << endl; // 洛谷P3366题目中要求输出"orz"
    } else {
        cout << result << endl;
    }
    
    return 0;
}