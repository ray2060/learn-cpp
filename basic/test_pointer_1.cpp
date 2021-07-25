#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int *p;
    int **pp;
    int a;
    cin >> a;
    p = &a;
    pp = &p;
    cout << *pp;
    return 0;
}
