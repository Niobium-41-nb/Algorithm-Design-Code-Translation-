/*
    递推二分查找

作者: vanadium-23(Niobium-41-nb)

*/

#include <iostream>
using namespace std;

const int maxn = 1e6;

int A[maxn],x;

int binarysearch(int low,int high){
    if(low > high)return 0;
    int mid = (low+high)/2;
    if(x == A[mid])return mid;
    else if (x < A[mid])return binarysearch(low,mid-1);
    binarysearch(mid+1,high);
}

int main(){
    int n;
    cin >> n >> x;
    for(int i = 1;i <= n;i++){
        cin >> A[i];
    }

    cout << binarysearch(1,n) << '\n';

    return 0;
}
