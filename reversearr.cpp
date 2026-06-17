#include <iostream>
using namespace std;

void f(int arr[],int l,int r){
    if (l>=r){
        return ;

    }
    else{
    swap(arr[l],arr[r]);
    }
    f(arr ,l+1,r-1);
}
int main (){
    int arr[5]={1,2,5,8,4};
     int n = 5;
    f( arr ,0,n-1);
    for (int i = 0;i<n;i++){
        cout << arr[i];
    }
    
}