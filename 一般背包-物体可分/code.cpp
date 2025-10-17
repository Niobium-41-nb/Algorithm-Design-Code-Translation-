/*
    一般背包-物体可分

作者：vanadium-23(Niobium-41-nb)
例题：https://www.luogu.com.cn/problem/P2240
*/

#include <bits/stdc++.h>
using namespace std;

struct wuping{
    int val;
    int wight;
    bool operator < (const wuping a) const {
        double this_ = (double)val/(double)wight;
        double a_ = (double)a.val/(double)a.wight;
        return this_ < a_;
    }
};

int main(){
    int W,n;
    cin >> n >> W;
    vector<wuping>arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i].wight>> arr[i].val;
    }
    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    double ans = 0.0;
    for(int i = 0;i < n && W > 0;i++){
        if(W > arr[i].wight){
            ans = (ans + arr[i].val);
            W -= arr[i].wight;
        }else{
            ans = (ans + W*(double)arr[i].val/(double)arr[i].wight);
            W = 0;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
    // cout << ans << endl;
    return 0;
}