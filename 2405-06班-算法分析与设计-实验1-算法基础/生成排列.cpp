#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n;

void dfs(vector<int>arr,set<int>st,int dep,int last = 0){
    if(st.find(last) != st.end()){
        st.erase(last);
    }
    if(dep == n){
        for(int i : arr){
            cout << i << ' ';
        }
        cout << endl << endl;
        return;
    }
    for(int i : st){
        arr.push_back(i);
        dfs(arr,st,dep+1,i);
        arr.pop_back();
    }

}

void solve() {
    cin >> n;
    set<int>st;
    vector<int>arr;
    for(int i = 1;i <= n;i++){
        st.insert(i);
    }
    dfs(arr,st,0);
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