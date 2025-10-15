/*
    分治法-求和

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
#include <vector>
using namespace std;
struct node{
    int data;
};

void build(const vector<int>&datas,vector<node>&tree,int rt,int left,int right){
    if(left == right){
        tree[rt].data=datas[left];
        return;
    }
    int mid = left+(right-left)/2;
    build(datas,tree,2*rt,left,mid);
    build(datas,tree,2*rt+1,mid+1,right);
    tree[rt].data = tree[2*rt].data+tree[2*rt+1].data;
}

int query(vector<node>&tree,int rt,int left,int right,int ql,int qr){
    if(ql > right || qr < left){
        return 0;
    }
    if(ql <= left && qr >= right){
        return tree[rt].data;
    }
    int mid = left+(right-left)/2;
    int leftsum = query(tree,2*rt,left,mid,ql,qr);
    int rightsum = query(tree,2*rt+1,mid+1,right,ql,qr);
    return leftsum+rightsum;
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n+1,0);
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    vector<node>tree(4*n);
    build(arr,tree,1,1,n);
    cout << query(tree,1,1,n,1,n) << endl;
    return 0;
}