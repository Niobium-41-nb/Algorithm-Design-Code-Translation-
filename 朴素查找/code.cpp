/*
    朴素查找

作者: vanadium-23(Niobium-41-nb)
例题：https://www.luogu.com.cn/problem/B2093

*/

#include <iostream>
using namespace std;
const int maxn = 2e6;

int A[maxn];

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> A[i];
    }
    int x;
    cin >> x;
    int j = 0;
    while(j < n-1 && x != A[j]){
        j = j+1;
    }
    if(x == A[j]){
        cout << j << '\n';
    }else{
        cout << -1 << '\n';
    }
    return 0;
}