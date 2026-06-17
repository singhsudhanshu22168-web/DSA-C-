#include <iostream>
using namespace std;

int main (){
    int nums [] = {5,15,24,-1,8};
    int size = 5;

    int smallest = INT16_MAX; // as same we find largest value use INT_MIN
    int largest = INT16_MIN;
    for (int i = 0; i < size ; i++){ // min or max
      //  if (nums[i] <smallest){
          //  smallest = nums[i];
          smallest = min(nums[i] , smallest);
           largest = max (nums[i] , largest);

    } 
        cout << "smallest : " << smallest << endl; // & use to print the address of the value 
        cout << "largest : "<< largest << endl;

    return 0;
    
}