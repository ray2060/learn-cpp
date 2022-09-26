#include <iostream>
#include <cstdio>

using namespace std;

struct TO {
    template <class T>
    TO operator <<(const T x) {
        cout << x;
        TO temp;
        return temp;
    }
};

TO tout;
char newline = '\n';

int main() {
    tout << 1 << newline;
    tout << 1 << ' ' << 2 << newline;
    tout << "Hello, C++ !" << newline;
    return 0;
}