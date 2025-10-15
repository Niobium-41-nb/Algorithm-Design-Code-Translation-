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
int get(int num,int k){
    num = num / binpow(10,k-1);
    return num % 10;
}
void Sort(vector<int>&arr,int n){
    // sort(arr.begin()+1,arr.end());
    vector<int>t[10];
    for(int w = 1;w <= 5;w++){
        vector<int>t[10];
        for(int i = 1;i <= n;i++){
            int g = get(arr[i],w);
            t[g].push_back(arr[i]);
        }
        arr.clear();
        arr.push_back(0);
        for(int l = 0;l <= 9;l++){
            for(int i : t[l]){
                arr.push_back(i);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int>arr(n+1,0);
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    Sort(arr,n);
    for(int i =1;i <= n;i++){
        cout << arr[i] << ' ' ;
    }
    cout << endl;
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