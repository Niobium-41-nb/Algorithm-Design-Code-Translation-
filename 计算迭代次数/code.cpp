#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0;
    while(n >= 1){
        for(int j = 1;j <= n;j++){
            count = count + 1;
        }
        n = n/2;
    }
    cout << count  << '\n';
    return 0 ;
}