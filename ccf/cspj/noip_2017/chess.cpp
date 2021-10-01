#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int a[110][110];
int dp[110][110];
int step[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int m, n;
int ans = 1e9;

void dfs(int x, int y, int cost, bool change) {
    if (x < 1 || y < 1 || x > m || y > m) return;
    if (a[x][y] == 0) return;
    if (cost >= dp[x][y]) return;
    
    if (x == m && y == m) {
        ans = min(ans, cost);
        dp[x][y] = ans;
        return;
    }
    
    dp[x][y] = cost;
    for (int i = 0; i < 4; i ++ ) {
        dfs(x + step[i][0], 
                y + step[i][1], 
                cost + abs(a[x][y] - a[x + step[i][0]][y + step[i][1]]), 
                false
            );
    }
    if (!change) {
        for (int i = 0; i < 4; i ++ ) {
            if (a[x + step[i][0]][y + step[i][1]] == 0) {
                a[x + step[i][0]][y + step[i][1]] = a[x][y];
                dfs(x + step[i][0], 
                        y + step[i][1],
                        cost + 2, 
                        true
                    );
                a[x + step[i][0]][y + step[i][1]] = 0;
            }
        }
    }
}

int main() {
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    cin >> m >> n;
    int x, y, c;
    for (int i = 0; i < n; i ++ ) {
        cin >> x >> y >> c;
        a[x][y] = c + 1;
    }
    for (int i = 1; i <= m; i ++ )
        for (int j = 1; j <= m; j ++ )
            dp[i][j] = 1e9;
    
    dfs(1, 1, 0, false);
    
    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
        
    return 0;
}
