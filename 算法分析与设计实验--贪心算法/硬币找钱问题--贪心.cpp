#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX / 2;
const int values[6] = {5, 10, 20, 50, 100, 200};

// 贪心找零函数
int greedyChange(int change) {
    int coins = 0;
    for (int i = 5; i >= 0; i--) {
        coins += change / values[i];
        change %= values[i];
    }
    return coins;
}

void solve(vector<int> Coins,double amount_double) {
    int amount = static_cast<int>(amount_double * 100 + 0.5); // 避免浮点误差
    
    int max_pay = amount + 200;
    
    vector<int> dp(max_pay + 1, INF);
    dp[0] = 0;
    
    for (int i = 0; i < 6; i++) {
        int num = Coins[i];
        int k = 1;
        while (num > 0) {
            int use = min(k, num);
            int weight = use * values[i];
            
            for (int j = max_pay; j >= weight; j--) {
                if (dp[j - weight] != INF) {
                    dp[j] = min(dp[j], dp[j - weight] + use);
                }
            }
            
            num -= use;
            k *= 2;
        }
    }
    
    int ans = INF;
    for (int pay = amount; pay <= max_pay; pay++) {
        if (dp[pay] != INF) {
            int change = pay - amount;
            int change_coins = greedyChange(change);
            int total = dp[pay] + change_coins;
            ans = min(ans, total);
        }
    }
    
    cout << ans << endl;
    
    return;
}

signed main(){
    vector<int> Coin(6);
    double amount_double;
    while(true){
        cin >> Coin[0] >> Coin[1] >> Coin[2] >> Coin[3] >> Coin[4] >> Coin[5] >>amount_double;
        if(Coin[0] == 0 && Coin[1] == 0 && Coin[2] == 0 && Coin[3] == 0 && Coin[4] == 0 && Coin[5] == 0){
            break;
        }
        solve(Coin,amount_double);
    }
}