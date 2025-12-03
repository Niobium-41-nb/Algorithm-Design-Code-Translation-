#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<int>tree(2000,0);
string s;
int step = 0;
int n;

void inder(int index){
    if(step >= n)return;
    
    if(s[step] == '^'){
        return;
    }else{
        tree[index] = 1;
    }
    step++;
    inder(2*index);
    step++;
    inder(2*index+1);
}
int h(int index){
    if(tree[index] == 0)return 0;
    return max(h(2*index),h(2*index+1))+1;
}
void debug(){
    for(int i = 1;i <= 30;i++){
        cout << "tree[i] = ";
        cout << tree[i] << endl;
    }
}
void solve() {
    cin >> s;
    n = s.size();
    // cout << s << endl;
    inder(1);
    // debug();
    cout << h(1);
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