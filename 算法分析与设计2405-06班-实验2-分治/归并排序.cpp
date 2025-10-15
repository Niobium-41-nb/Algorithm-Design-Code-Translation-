/*
    归并排序

作者: vanadium-23(Niobium-41-nb)
*/

#include <iostream>
using namespace std;
const int maxn = 2e6;

int A[maxn+1];
int B[maxn+1];

void MERGE(int A[],int p,int q,int r){
    int s=p,t=q+1,k=p;
    while(s <= q && t <= r){
        if(A[s] <= A[t]){
            B[k]=A[s];s=s+1;
        }else{
            B[k]=A[t];t=t+1;
        }
        k++;
    }
    if(s == q+1){
        for(int i=k,j=t;i<=r&&j<=r;i++,j++){
            B[i] = A[j];
        }
    }else{
        for(int i=k,j=s;i<=r&&j<=q;i++,j++){
            B[i] = A[j];
        }
    }
    for(int i = p;i <= r;i++){
        A[i] = B[i];
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> A[i];
    }
    int t = 1; 
    while (t < n) {
        int s=t;t=2*s;int i=0;
        while (i + t <= n) {
            MERGE(A, i + 1, i + s, i + t);
            i = i + t;
        }
        if (i + s < n) {
            MERGE(A, i + 1, i + s, n);
        }
    }
    for(int i = 1;i <= n;i++){
        cout << A[i] << ' ';
    }
    cout << '\n';
}
