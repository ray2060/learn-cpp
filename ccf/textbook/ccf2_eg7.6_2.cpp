#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 1030;
int cnt[MAXN][MAXN], n, d;

int main() {
    for (int i = 0; i < 1025; i ++ ) {
        for (int j = 0; j < 1025; j ++ ) {
            cnt[i][j] = 0;
        }
    }
    cin >> d >> n;
    for (int m = 1; m <= n; m ++ ) {
        int x, y, i;
        cin >> x >> y >> i;
        cnt[x][y] = i;
    }
    for (int i = 1; i < 1025; i ++ ) {
        cnt[0][i] += cnt[0][i - 1];
        cnt[i][0] += cnt[i - 1][0];
    }
    for (int i = 1; i < 1025; i ++ ) {
        for (int j = 1; j < 1025; j ++ ) {
            cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
        }
    }
    int maxval = -1; int num = 0;
    for (int i = 0; i < 1025; i ++ ) {
        for (int j = 0; j < 1025; j ++ ) {
            int li = max(i - d, 0); int ri = min(1024, i + d);
            int dj = max(j - d, 0); int uj = min(1024, j + d);
            int t = cnt[ri][uj];
            if (dj > 0) t -= cnt[ri][dj - 1];
            if (li > 0) t -= cnt[li - 1][uj];
            if (li > 0 && dj > 0) t += cnt[li - 1][dj - 1];
            if (t > maxval) {
                maxval = t;
                num = 1;
            }
            else if (t == maxval) num ++ ;
        }
    }
    cout << num << ' ' << maxval << endl;
    return 0;
}
