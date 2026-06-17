#include <iostream>
using namespace std;

//  USING TWO POINTER APPROCH
void reversearray(int arr[] , int sz  ){
    int start = 0 , end = sz - 1;
    while (start < end ){
        swap (arr[start] ,arr[end]);
        start++;
        end--;
    }
}
int main (){

    int arr[] = { 1,3,4,5,6,7 };
    int sz = 6;

     reversearray(arr,sz);

     for (int i = 0; i < sz ; i++){
        cout << arr[i]<< " ";
     }
     cout << endl;
    return 0;
}