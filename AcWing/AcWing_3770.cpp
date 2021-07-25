#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T --) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;
        int res = 0;
        for (int i = 0; i < s.size(); i ++ ) {
            if (s[i] == '0') {
                if (a < b + c) res += a;
                if (a >= b + c) res += b + c;
            }
            if (s[i] == '1') {
                if (b < a + c) res += b;
                if (b >= a + c) res += a + c;
            }
        }
        cout << res << endl;
    }
}
