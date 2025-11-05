#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
    double x, y;
};

double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });

    vector<vector<double>> dp(n, vector<double>(n, 1e20));

    dp[0][1] = dist(points[0], points[1]);

    for (int j = 2; j < n; j++) {
        for (int i = 0; i < j - 1; i++) {
            dp[i][j] = dp[i][j - 1] + dist(points[j - 1], points[j]);
        }
        for (int k = 0; k < j - 1; k++) {
            dp[j - 1][j] = min(dp[j - 1][j], dp[k][j - 1] + dist(points[k], points[j]));
        }
    }

    double ans = 1e20;
    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, dp[i][n - 1] + dist(points[i], points[n - 1]));
    }

    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}