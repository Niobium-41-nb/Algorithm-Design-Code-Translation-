/*
    选择排序

作者: vanadium-23(Niobium-41-nb)

*/

#include <iostream>
using namespace std;

const int maxn = 1e6;

int A[maxn];

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> A[i];
    }
    for(int i = 1;i <= n-1;i++){
        int k = i;
        for(int j = i+1;j <= n;j++){
            if(A[j]<A[k]){
                k=j;
            }
        }
        if(k != i){
            int tmp=A[i];A[i]=A[k];A[k]=tmp;
        }
    }
    for(int i = 1;i <= n;i++){
        cout << A[i] << ' ';
    }
    cout << endl;
}