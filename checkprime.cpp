#include <iostream>
using namespace std;
bool isprime(int num){
    if (num <=1){
        return false;
    }
    for (int i = 2; i * i <num ; i++){
        if (num % i == 0){
            return false ;
        }
        return true;
    }
}
int main (){
int n;
cout << "Enter a Number :";
cin >> n;
if (isprime(n)){
    cout << " is a prime " << endl;
}
else {
    cout << " is not a prime"<< endl;
}
return 0;
}