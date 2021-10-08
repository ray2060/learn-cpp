#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    freopen("title.in", "r", stdin);
    freopen("title.out", "w", stdout);
    int l = 0;
    char c;
    while (cin >> c) {
        if (c != ' ' && c != '\n') l ++;
    }
    cout << l << endl;
    return 0;
}