#include <iostream>
using namespace std;

int main() {
    int num, reverse = 0, remainder;

    cout << "Enter a number: ";
    cin >> num;

    while (num != 0) {
        remainder = num % 10;          // get last digit
        reverse = reverse * 10 + remainder;
        num = num / 10;                // remove last digit
    }

    cout << "Reversed number: " << reverse;

    return 0;
}
