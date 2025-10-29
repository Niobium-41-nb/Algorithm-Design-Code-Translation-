#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n;
void dfs(set<int>st,int dep,vector<int>arr) {
    if(dep == n){
        for(int i : arr){
            cout << i << ' ' ;
        }
        cout << endl;
        return;
    }
    for(int i : st){
        set<int>tmp = st;
        tmp.erase(i);
        arr.push_back(i);
        dfs(tmp,dep+1,arr);
        arr.pop_back();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    set<int>st;
    vector<int>arr;
    cin >> n;
    for(int i = 1;i <= n;i++){
        st.insert(i);
    }
    for(int i : st){
        set<int>tmp = st;
        tmp.erase(i);
        arr.push_back(i);
        dfs(tmp,1,arr);
        arr.pop_back();
    }
    return 0;
}

// by vanadium-23