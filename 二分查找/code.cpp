/*
    二分查找

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
using namespace std;
const int maxn = 1e6;

int A[maxn];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> A[i];
    }
    while(m--){
        int x;cin >> x;
        int low=1,high=n,j=0;
        while(low <= high && j==0){
            int mid=(low+high)/2;
            if(x==A[mid])j=mid;
            else if(x < A[mid])high=mid-1;
            else low = mid+1;
        }
        cout << j << '\n';
    }
    return 0;
}