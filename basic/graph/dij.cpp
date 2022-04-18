#include <cstdio>
#include <cstring>
#define min(x, y) x < y ? x : y

using namespace std;

const int N = 510;

int n, m;
int g[N][N], dist[N];
bool st[N];


int dij() {
    memset(dist, 0x3f, (sizeof dist));
    dist[1] = 0;
    
    for (int i = 1; i <= n; i ++ ) {
        int t = 0;
        for (int j = 1; j <= n; j ++ ) {
            if (dist[j] <= dist[t] && !st[j]) {
                t = j;
            }
        }
        st[t] = true;
        for (int j = 1; j <= n; j ++ ) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if (dist[n] == 0x3f3f3f3f) {
        return -1;
    }
    return dist[n];
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v, w;
    for (int i = 0; i < m; i ++ ) {
        scanf("%d%d%d", &u, &v, &w);
        if (g[u][v]) g[u][v] = min(g[u][v], w);
        else g[u][v] = w;
    }
    
    int res = dij();
    printf("%d", res);
    return 0;
}