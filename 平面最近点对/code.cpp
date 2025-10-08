#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 4e18;  // 因为坐标范围是±1e9，平方后最大约1e18

struct Point {
    int x, y;
    bool operator < (const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

vector<Point> points, temp;

int dist(const Point& a, const Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int closestPair(int l, int r) {
    if (l >= r) return INF;
    
    // 小范围直接暴力
    if (r - l + 1 <= 3) {
        int minDist = INF;
        for (int i = l; i <= r; i++) {
            for (int j = i + 1; j <= r; j++) {
                minDist = min(minDist, dist(points[i], points[j]));
            }
        }
        return minDist;
    }
    
    int mid = (l + r) >> 1;
    int mid_x = points[mid].x;
    
    // 递归求解左右两半
    int leftDist = closestPair(l, mid);
    int rightDist = closestPair(mid + 1, r);
    int minDist = min(leftDist, rightDist);
    
    // 合并：处理跨越中线的点对
    temp.clear();
    
    // 收集中间带状区域的点（x坐标在[mid_x - d, mid_x + d]范围内）
    for (int i = l; i <= r; i++) {
        int dx = points[i].x - mid_x;
        if (dx * dx <= minDist) {
            temp.push_back(points[i]);
        }
    }
    
    // 按y坐标排序
    sort(temp.begin(), temp.end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
    });
    
    // 在带状区域内检查可能的更近点对
    // 每个点只需要与后面有限的几个点比较（y坐标差小于d）
    for (int i = 0; i < temp.size(); i++) {
        for (int j = i + 1; j < temp.size(); j++) {
            int dy = temp[j].y - temp[i].y;
            if (dy * dy >= minDist) break;  // 由于按y排序，后面的点y坐标差更大
            minDist = min(minDist, dist(temp[i], temp[j]));
        }
    }
    
    return minDist;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    // 按x坐标排序
    sort(points.begin(), points.end());
    
    cout << closestPair(0, n - 1) << endl;
    
    return 0;
}