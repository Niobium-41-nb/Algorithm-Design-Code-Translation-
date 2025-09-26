/*
    选择排序(递归)

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
using namespace std;


const int maxn = 1e6;
int A[maxn],n;

void sort(int i){
    if(i < n){
        int k = i;
        for(int j = i+1; j <= n; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        if(k != i){
            swap(A[i],A[k]);
        }
        sort(i+1);
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    sort(1);
    for(int i = 1; i <= n; i++){
        cout << A[i] << ' ';
    }
    return 0;
}