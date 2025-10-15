/*
    邮局选址问题

作者：vanadium-23(Niobium-41-nb)

*/

#include <bits/stdc++.h>
using namespace std;

struct place{
    int x,y;
};

int main(){
    int n;
    cin >> n;
    vector<place>arr(n);
    vector<int>x(n);
    vector<int>y(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i].x >> arr[i].y;
        x[i] = arr[i].x;
        y[i] = arr[i].y;
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int midx = x[n/2];
    int midy = y[n/2];
    int ans = 0;
    for(int i = 0;i < n;i++){
        ans += abs(midx-arr[i].x) + abs(midy-arr[i].y);
    }
    cout << ans;


    return 0;
}