#include <iostream>
using namespace std;

class Complex {
public:
    int real;
    int img;

    Complex(int x, int y) {
        real = x;
        img = y;
    }

    Complex operator+ (const Complex &c) {
        Complex ans(0,0);
        ans.real = real + c.real;
        ans.img = img + c.img;
        return ans;
    }
};

int main() {
    Complex c1(1, 2);
    Complex c2(1, 3);

    Complex c3 = c1 + c2;

    cout << c3.real << "+" << c3.img << "i" << endl;
    return 0;
}
