#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isprime(int n) {
    int m = ceil(sqrt(n));
    for (int i = 2; i <= m; i ++) if (n % i == 0) return false;
    return true;
}

int main() {
    int n;
    bool empty = true;
    cin >> n;
    for (int i = 2; i < n - 2; i ++) {
        if (isprime(i) && isprime(i + 2)) {
            empty = false;
            cout << i << ' ' << i + 2 << endl;
        }
    }
    if (empty) cout << "empty";
    return 0;
}
