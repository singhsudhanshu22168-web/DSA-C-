#include <iostream>
#include <vector>
using namespace std;
int main ()
{
  //  vector<int>vec = {1,3,5};
  //  cout << vec[0]<< endl;

    vector<char>vec = {'a' , 'b' , 'c' , 'd'};   // Using  For each loop
     for (char val : vec){
        cout << val << endl;
     }
    return 0;
}