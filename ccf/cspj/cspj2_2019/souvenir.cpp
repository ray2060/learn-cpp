#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, M = 10010;

int t, n, m;
int p[N][N];

// dp[m]表示手里有m枚金币时能获得的金币增量的最大值
int dp[M];

int main() {
    cin >> t >> n >> m;
    for (int i = 1; i <= t; i ++ )
        for (int j = 1; j <= n; j ++ )
            cin >> p[i][j];
    
    for (int i = 1; i < t; i ++ ) {
        memset(dp, 0, sizeof dp);
        for (int j = 1; j <= n; j ++ )
            if (p[i + 1][j] > p[i][j])    // j物品涨价
                // 必将在第i + 1天卖出
                // 完全背包
                for (int k = p[i][j]; k <= m; k ++ )
                    dp[k] = max(dp[k], dp[k - p[i][j]] + p[i + 1][j] - p[i][j]);
        m += dp[m];
    }
    
    cout << m << endl;
    return 0;
}
