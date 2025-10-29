#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int>arr;
    for(int i =1;i <= n;i++){
        int tmp;cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    int ans = 0;
    int sum = 0;
    for(int i : arr){
        if(sum + i > k){
            cout << ans <<endl;
            return;
        }else{
            sum += i;
            ans++;
        }
    }
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// by vanadium-23