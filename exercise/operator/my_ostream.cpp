#include <iostream>

using namespace std;

struct test_output {
    template <class T>
    test_output operator <<(const T x) {
        cout << x;
        test_output temp;
        return temp;
    }
};
test_output tout;
char newline = '\n';

int main() {
    tout << 1 << newline;
    tout << 1 << ' ' << 2 << newline;
    tout << "Hello, C++ !" << newline;
    return 0;
}