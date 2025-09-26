/*
    排列生成

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
using namespace std;
const int MAXN = 20;
int P[MAXN];
int n;

void perm1(int m) {
    if (m == n) {
        for (int i = 1; i <= n; i++) {
            cout << P[i] << ' ';
        }
        cout << endl;
    } else {
        for (int j = m; j <= n; j++) {
            // 交换 P[j] 和 P[m]
            int tmp = P[j];
            P[j] = P[m];
            P[m] = tmp;

            perm1(m + 1);

            // 交换回来
            tmp = P[j];
            P[j] = P[m];
            P[m] = tmp;
            // 此时 P[m..n] = m, m+1, ..., n
        }
    }
}

int main() {
    cin >> n;
    for (int j = 1; j <= n; j++) {
        P[j] = j;
    }
    perm1(1);
    return 0;
}