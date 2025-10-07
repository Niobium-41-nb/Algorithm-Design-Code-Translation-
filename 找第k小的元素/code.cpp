/*
    找第k小的元素

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 函数声明
int select(vector<int>& A, int low, int high, int k);

// 主函数
int SELECT(vector<int>& A, int k) {
    if (k < 1 || k > A.size()) {
        throw out_of_range("k is out of range");
    }
    return select(A, 0, A.size() - 1, k);
}

// 递归选择过程
int select(vector<int>& A, int low, int high, int k) {
    int p = high - low + 1;
    
    // 步骤2：如果元素数量小于44，直接排序返回
    if (p < 44) {
        vector<int> temp(A.begin() + low, A.begin() + high + 1);
        sort(temp.begin(), temp.end());
        return temp[k - 1];
    }
    
    // 步骤3：将元素分成每组5个的若干组
    int q = p / 5;
    vector<int> M;
    
    // 步骤4：对每组排序并找出中位数
    for (int i = 0; i < q; i++) {
        vector<int> group(5);
        for (int j = 0; j < 5; j++) {
            group[j] = A[low + i * 5 + j];
        }
        sort(group.begin(), group.end());
        M.push_back(group[2]); // 取中位数
    }
    
    // 步骤5：递归找出中位数的中位数
    int mm = select(M, 0, M.size() - 1, M.size() / 2);
    
    // 步骤6：将数组分成三组
    vector<int> A1, A2, A3;
    for (int i = low; i <= high; i++) {
        if (A[i] < mm) {
            A1.push_back(A[i]);
        } else if (A[i] == mm) {
            A2.push_back(A[i]);
        } else {
            A3.push_back(A[i]);
        }
    }
    
    // 步骤7：根据情况递归处理
    if (k <= A1.size()) {
        return select(A1, 0, A1.size() - 1, k);
    } else if (k <= A1.size() + A2.size()) {
        return mm;
    } else {
        return select(A3, 0, A3.size() - 1, k - A1.size() - A2.size());
    }
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int>arr(n,0);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    cout << SELECT(arr,k) << endl;
    return 0;
}