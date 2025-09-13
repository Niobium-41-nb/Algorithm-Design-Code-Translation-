/*
    插入排序

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
    for(int i = 2;i <= n;i++){
        int x = A[i];
        int j = i-1;
        while(j > 0 && A[j] > x){
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1]=x;
    }
    for(int i = 1;i <= n;i++){
        cout << A[i] << ' ';
    }
    cout << endl;
}