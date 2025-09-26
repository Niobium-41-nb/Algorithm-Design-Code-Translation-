/*
    插入排序(递归)

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
using namespace std;


const int maxn = 1e6;
int A[maxn],n;

void sort(int i){
    if(i > 1){
        int x = A[i];
        sort(i-1);
        int j = i-1;
        while(j > 0 && A[j] > x){
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = x;
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    sort(n);
    for(int i = 1; i <= n; i++){
        cout << A[i] << ' ';
    }
    return 0;
}