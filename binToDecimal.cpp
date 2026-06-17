#include <iostream>
using namespace std;
int binToDecimal (int binNum){
    int ans = 0 , pow = 1;
    while (binNum > 0){
        int rem = binNum % 10;
        ans += (rem * pow);
        binNum = binNum / 10;
        pow = pow * 2;
    }
    return ans; // Decimal form 
}
int main (){
    int binNum = 110010;

    cout << binToDecimal(binNum) << endl;
    return 0;
}