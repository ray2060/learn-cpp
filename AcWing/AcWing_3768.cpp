#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char s[100];
    for (int i = 0; i < n; i ++ ) cin >> s[i];
    int arr[43];
    memset(arr, 0, 43 * 4);
    int m = 0;
    for (int i = 0; i < n; i ++ ) {
        if (s[i] != 'x' && s[i - 1] == 'x') m += 1;
        if (s[i] == 'x') arr[m] ++;
    }
    m ++;
    int ans = 0;
    for (int i = 0; i < m; i ++ ) {
        if (arr[i] >= 3) ans += arr[i] - 2;
    }
    cout << ans;
}
