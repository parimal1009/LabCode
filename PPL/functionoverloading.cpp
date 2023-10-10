#include<iostream>
using namespace std;

class Sum {
public:
    void add(int x, int y) {
        int sum = x + y;
        cout << sum << endl;
    }

    void add(int x, int y, int z) {
        int sum = x + y + z;
        cout << sum << endl;
    }

    void add(float x, float y) {
        float sum = x + y;
        cout << sum << endl;
    }
};

int main() {
    Sum s;
    s.add(1, 3);
    s.add(32, 1, 2);
    s.add(float(23.12), float(23.32));

    return 0;
}
