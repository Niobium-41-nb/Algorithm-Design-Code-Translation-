/*
    最大字段和

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    int prv_min = 0;
    int prv = 0;
    vector<int>arr(n+1,0);
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        prv += arr[i];
        prv_min = min(prv_min,prv);
        ans = max(ans,prv-prv_min);
    }
    cout << ans << endl;
    return 0;
}