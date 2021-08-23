#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int m = 13;

int main() {
    char str[100];
    cin >> str;
    int n;
    cin >> n;
    memset(str + m, '$', n);
    cout << str;
    return 0;
}
