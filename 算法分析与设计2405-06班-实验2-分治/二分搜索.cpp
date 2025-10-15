/*
    二分搜索

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n,0);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int x;
    cin >> x;
    int l = 0,r = n-1;
    for(int i = 0;l < r && i < 10;i++){
        int mid = (l+r+1)/2;
        // cout << "mid = " << mid << endl;
        // cout << " l = " << l << " r = " << r << endl;
        if(arr[mid] <= x){
            l = mid;
        }else{
            r = mid-1;
        }
    }
    if(arr[l] == x){
        cout << l << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}