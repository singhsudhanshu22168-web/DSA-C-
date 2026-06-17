#include <iostream>
using namespace std;

// USING LINEAR SEARCH

int linearsearch (int arr[], int size , int target){
    for (int i = 0; i < size ; i++ ){
        if (arr[i] == target){
            return i ;  // found

        }
    }
    return -1;  //not found
}
    

int main (){
    int arr [] = {2,3,6,7,1,8,9,5};  //target = 9
    int size = 8;
    int target = 9; 

    cout << linearsearch( arr , size , target) << endl;
    return 0;

}