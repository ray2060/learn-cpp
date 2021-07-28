#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int n, m, a[110000];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    a[0] = -1;
    while (m -- ) {
        int x;
        int left = 1, right = n, mid;
        cin >> x;
        while (true) {
            mid = (left + right) / 2;
            if (a[mid] < x) left = mid + 1;
            else if (a[mid] > x) right = mid - 1;
            else {
                cout << a[mid] << endl;
                break;
            }
            if (left > right) {
                cout << a[right] << endl;
                break;
            }
        }
    }
    return 0;
}
