#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    vector<int>a(n+1,0);
    vector<int>b(n+1,0);
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = 1;i <= n;i++)cin >> b[i];
    int ans = INF;
    for(int k = 0;k <= (1 << n)-1;k++){
        int suma = 0;
        int sumb = 0;
        for(int i = 1;i <= n;i++){
            int z = (1 << (i-1));
            if(k & z){
                suma += a[i];
            }else{
                sumb += b[i];
            }
        }
        ans = min(ans,max(suma,sumb));
    }
    cout << ans << endl;
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