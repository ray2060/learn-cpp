#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int ans[32];
int n, l;
int get(int m) {
    return 1 << (int)floor(log2(m));
}
int main()
{
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout)
    cin >> n;
    if (n % 2) {
        cout << -1;
        return 0;
    }
    for (int i = 1, b = get(n);n > 0; n -= b, i ++ , b = get(n)) ans[i-1] = b, l ++ ;
    for (int j = 0; j < l; j ++ ) {
        cout << ans[j] << ' ';
    }
    return 0;
}