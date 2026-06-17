#include <iostream>
#include <vector>
using namespace std;

 int maxSubarray (vector<int> & nums){
    int currentSum = 0 , maxSum = INT16_MIN;
    for (int val : nums){                                    //INCOMPLETE Beacuse we cannot call the fuvtion in main function 
        currentSum = currentSum + val;
        maxSum = max(currentSum , maxSum);
        if (currentSum <0){
            currentSum = 0;
        }
    }
    return maxSum ;
 }

 int main (){
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int nums = 9;

    cout << maxSubarray (arr[])<< endl;
 }