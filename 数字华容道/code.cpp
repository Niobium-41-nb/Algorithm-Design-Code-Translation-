#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
bool is_red(pair<int,int>place_0){
    int x = place_0.first;
    int y = place_0.second;
    if(x % 2 == 0){
        if(y % 2 == 1){
            return true;
        }else{
            return false;
        }
    }else{
        if(y % 2 == 0){
            return true;
        }else{
            return false;
        }
    }
}
bool is_red(int num){
    int x = (num-1)/4;
    int y = (num-1)%4;
    return is_red({x,y});
}
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<vector<int>>goal={
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,0}
};
signed main() {
    int less = 0;
    vector<vector<int>>arr(4,vector<int>(4,0));
    pair<int,int>place_0;
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0){
                place_0 = {i,j};
            }else{
                if(arr[i][j] > goal[i][j]){
                    less++;
                }
            }
        }
    }
    less += is_red(place_0);
    if(less % 2 == 1){
        cout << "NO\n";
        return;
    }
    



    return 0;
}

// by vanadium-23