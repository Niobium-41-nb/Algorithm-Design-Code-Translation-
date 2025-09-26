/*
    快速幂(递归法)

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
using namespace std;

int power(int x,int m){
    int y;
    if(m == 0){
        y = 1;
    }else{
        y = power(x,m/2);
        y = y*y;
        if(m % 2 == 1)y = x*y;
    }
    return y;
}

int main(){
    int x,n;
    cin >> x >> n;
    cout << power(x,n);    
    return 0;
}