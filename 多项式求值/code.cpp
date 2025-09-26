/*
    多项式求值

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int>a(n+1,0);
    for(int i = 0;i <= n;i++){
        cin >> a[i];
    }
    int p = a[n];
    for(int j = 1;j <= n;j++){
        p = x*p + a[n-j];
    }
    cout << p << endl;
    return 0;
}