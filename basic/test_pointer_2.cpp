#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int *p[5];
    int a[5];
    for (int i = 0; i < 5; i ++ ) cin >> a[i];
    for (int i = 0; i < 5; i ++ ) {
        p[i] = &a[i];
    }
    for (int i = 0; i < 5; i ++ ) cout << *p[i];
    return 0;
}
