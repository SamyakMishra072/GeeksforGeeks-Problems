#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int temp = a;
    a = b;
    b = temp;

    cout << "After swapping: a = " << a << ", b = " << b << endl;
    return 0;
}
