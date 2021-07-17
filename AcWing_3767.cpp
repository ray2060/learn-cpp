#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100], b[100];
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    for (int i = 0; i < n; i ++ ) cin >> b[i];
    int x = 0, y = 0;
    for (int i = 0; i < n; i ++ ) {
        if (a[i] > b[i]) x ++ ;
        if (a[i] < b[i]) y ++ ;
    }
    if (x == 0) cout << -1;
    else if (x > y) cout << 1;
    else cout << int(y / x) + 1;
    return 0;
}
