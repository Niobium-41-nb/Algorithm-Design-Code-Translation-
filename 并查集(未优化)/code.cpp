/*
    并查集(未优化)

作者：vanadium-23(Niobium-41-nb)
例题：https://www.luogu.com.cn/problem/P3367
*/

#include <iostream>
using namespace std;
const int maxn = 2e5+1;

int A[maxn] = {0};

int FIND(int x){
    int y = x;
    while(A[y] != 0){
        y = A[y];
    }
    return y;
}

void UNION(int x,int y){
    int u = FIND(x);
    int v = FIND(y);
    if (u == v) return;
    A[u] = v;
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