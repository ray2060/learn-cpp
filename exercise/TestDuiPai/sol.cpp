#include <iostream>

using namespace std;

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.ans", "w", stdout);
    int a, b;
    cin >> a >> b;
    int ans = a + b;
    if (a % 60 == 0) ans ++;
    cout << ans << endl;
    return 0;
}