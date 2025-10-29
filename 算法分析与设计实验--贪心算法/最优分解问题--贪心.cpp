#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int ans = 0;
void f(set<int>st,int num,int n){
    if(n==0){
        int res = 1;
        for(int i : st){
            res *= i;
        }
        ans = max(ans,res);
    }
    for(int i = num-1;i >= 1;i--){
        st.insert(i);
        f(st,i,n-i);
        st.erase(i);
    }
}
void solve() {
    int n;
    cin >> n;
    set<int>st;
    for(int i = n;i >= 2;i--){
        st.insert(i);
        f(st,i,n-i);
        st.erase(i);
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