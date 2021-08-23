#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i ++ ) {
        int n;
        cin >> n;
        string x;
        cin >> x;
        string a, b;
        a = "1";
        b = "1";
        bool flag = false;
        for (int j = 1; j < n; j ++ ) {
            if (flag) {
                a += '0';
                b += x[j];
                continue;
            }
            if (x[j] == '0') {
                a += '0';
                b += '0';
            }
            if (x[j] == '1') {
                a += '1';
                b += '0';
                flag = true;
            }
            if (x[j] == '2') {
                a += '1';
                b += '1';
            }
        }
        cout << a << endl << b << endl;
    }
}
