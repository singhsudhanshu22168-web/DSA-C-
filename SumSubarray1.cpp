#include <iostream>
#include <vector>
using namespace std;
int main (){
    int arr[] = {5,3,-4,7,9,-1};
    int sz = 6;
    int  maxSum = INT16_MIN;
    for (int str = 0; str < sz ; str++){
        int currentSum = 0;
        for (int end = str ; end < sz; end++){
            currentSum = currentSum + arr[end] ;
            maxSum = max(currentSum , maxSum);
            
        }
        

    }
    cout << " max sum : " << maxSum ;
    return 0;
}