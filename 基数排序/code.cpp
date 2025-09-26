/*
    基数排序

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e6;
int n, k;
vector<int> l;

// 获取数字 num 的第 j 位数字（从最低位开始，j=1 表示个位）
int getDigit(int num, int j) {
    return (num / (int)pow(10, j - 1)) % 10;
}

int main() {
    cin >> n >> k;
    l.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    // 基数排序过程
    for (int j = 1; j <= k; j++) {
        // 准备10个空表 L0, L1, ..., L9
        vector<int> buckets[10];

        // 将元素按第 j 位数字分配到对应的桶中
        for (int i = 0; i < n; i++) {
            int digit = getDigit(l[i], j);
            buckets[digit].push_back(l[i]);
        }

        // 将桶中的元素按顺序放回原数组
        int index = 0;
        for (int i = 0; i < 10; i++) {
            for (int num : buckets[i]) {
                l[index++] = num;
            }
        }
    }

    // 输出排序后的结果
    for (int i = 0; i < n; i++) {
        cout << l[i] << ' ';
    }
    return 0;
}