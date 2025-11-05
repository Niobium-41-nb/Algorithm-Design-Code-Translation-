#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

struct Item {
    int code;
    int count;
    int price;
};

struct Offer {
    vector<pair<int, int>> items;
    int price;
};

int main() {
    int B;
    cin >> B;
    
    vector<Item> items(B);
    map<int, int> codeToIndex;
    
    for (int i = 0; i < B; i++) {
        cin >> items[i].code >> items[i].count >> items[i].price;
        codeToIndex[items[i].code] = i;
    }
    
    int S;
    cin >> S;
    
    vector<Offer> offers(S);
    
    for (int i = 0; i < S; i++) {
        int j;
        cin >> j;
        offers[i].items.resize(j);
        for (int k = 0; k < j; k++) {
            int code, count;
            cin >> code >> count;
            offers[i].items[k] = {code, count};
        }
        cin >> offers[i].price;
    }
    
    int dp[6][6][6][6][6];
    
    for (int a = 0; a <= 5; a++) {
        for (int b = 0; b <= 5; b++) {
            for (int c = 0; c <= 5; c++) {
                for (int d = 0; d <= 5; d++) {
                    for (int e = 0; e <= 5; e++) {
                        dp[a][b][c][d][e] = INT_MAX;
                    }
                }
            }
        }
    }
    
    dp[0][0][0][0][0] = 0;
    
    vector<int> target(5, 0);
    for (int i = 0; i < B; i++) {
        target[i] = items[i].count;
    }
    
    for (int a = 0; a <= target[0]; a++) {
        for (int b = 0; b <= target[1]; b++) {
            for (int c = 0; c <= target[2]; c++) {
                for (int d = 0; d <= target[3]; d++) {
                    for (int e = 0; e <= target[4]; e++) {
                        if (dp[a][b][c][d][e] == INT_MAX) continue;
                        
                        for (int i = 0; i < B; i++) {
                            vector<int> counts = {a, b, c, d, e};
                            if (counts[i] < target[i]) {
                                counts[i]++;
                                int cost = dp[a][b][c][d][e] + items[i].price;
                                if (cost < dp[counts[0]][counts[1]][counts[2]][counts[3]][counts[4]]) {
                                    dp[counts[0]][counts[1]][counts[2]][counts[3]][counts[4]] = cost;
                                }
                                counts[i]--;
                            }
                        }
                        
                        for (const auto& offer : offers) {
                            vector<int> newCounts = {a, b, c, d, e};
                            bool valid = true;
                            
                            for (const auto& item : offer.items) {
                                int code = item.first;
                                int required = item.second;
                                
                                if (codeToIndex.find(code) != codeToIndex.end()) {
                                    int idx = codeToIndex[code];
                                    if (newCounts[idx] + required > target[idx]) {
                                        valid = false;
                                        break;
                                    }
                                    newCounts[idx] += required;
                                } else {
                                    valid = false;
                                    break;
                                }
                            }
                            
                            if (valid) {
                                int cost = dp[a][b][c][d][e] + offer.price;
                                if (cost < dp[newCounts[0]][newCounts[1]][newCounts[2]][newCounts[3]][newCounts[4]]) {
                                    dp[newCounts[0]][newCounts[1]][newCounts[2]][newCounts[3]][newCounts[4]] = cost;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << dp[target[0]][target[1]][target[2]][target[3]][target[4]] << endl;
    
    return 0;
}