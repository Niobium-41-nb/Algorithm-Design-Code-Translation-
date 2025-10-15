#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 50;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
vector<int>arr(N+1,0);
void solve() {
    int n;
    cin >> n;
    cout << arr[n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    arr[1]=arr[2]=1;
    for(int i = 3;i <= N;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// by vanadium-23