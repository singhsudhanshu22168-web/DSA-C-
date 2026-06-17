#include <iostream>
using namespace std;
int main (){
    
    int n ;
    cin >> n;
    int arr[n];
    int sum = 0;
    cout << n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        sum +=arr[i];
    }
    cout << sum << endl;
    return 0;
    

}