#include<iostream>

using namespace std;

int main() {
    int n, a;
    cin >> n;
    a = 1;
    for(int i = 1; i <= n; i++) {
        a = a * i;
    }
    cout << a;
    return 0;
}
