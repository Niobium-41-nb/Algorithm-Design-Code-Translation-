/*
    并查集(路径压缩优化)

作者：vanadium-23(Niobium-41-nb)
例题：https://www.luogu.com.cn/problem/P3367
*/

#include <iostream>
using namespace std;
const int maxn = 2e5+1;

int A[maxn] = {0};
int Rank[maxn] = {0};

int FIND(int x){
    int y = x;
    while(A[y] != 0){
        y = A[y];
    }
    int root = y;y = x;
    while(A[y] != 0){
        int w = A[y];
        A[y] = root;
        y = w;
    }
    return root;
}

void UNION(int x, int y) {
    int u = FIND(x);
    int v = FIND(y);
    if (u == v) return;  
    if(Rank[u] <= Rank[v]){
        A[u] = v;
        if(Rank[u] == Rank[v])Rank[v] = Rank[v]+1;
    }else{
        A[v] = u;
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    while(M--){
        int op,x,y;
        cin >>op >> x >> y;
        if(op == 1){
            UNION(x,y);
        }else{
            if(FIND(x) == FIND(y)){
                cout << "Y\n";
            }else{
                cout << "N\n";
            }
        }
    }
    return 0;
}