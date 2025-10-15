/*
    整数因子分解问题

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
#include <vector>
using namespace std;
int f(int num){
    int res = 1;
    for(int i = 2;i * i <= num;i++){
        if(num % i == 0){
            res += f(i);
            if(i * i != num)res += f(num/i);
        }
    }
    // cout << "f(" << num << ") = " << res << endl;
    return res;
}
int main(){
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}