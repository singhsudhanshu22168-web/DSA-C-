#include <iostream>
using namespace std;

// function to print fibonacci series
void fibonacci(int n) {
    int a = 0, b = 1, c;

    cout << "Fibonacci Series: ";
    for (int i = 1; i <= n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    fibonacci(n);

    return 0;
}
