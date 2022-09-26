#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int g[N][N], dist[N][N];
bool st[N][N];

struct Point {
    int x, y, dist;
    Point(int a, int b, int c) {
        x = a;
        y = b;
        dist = c;
    }
}

bool check(Point x) {
    return x.x >= 1 && x.x <= n && x.y >= 1 && x.y <= n && x.dist < dist[x.x][x.y] && g[];
}

int main() {
    memset(dist, 0x3f, sizeof dist);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            cin >> g[i][j];
    queue<Point> q;
    q.push(Point(1, 1, 0));
    st[1][1] = true;
    dist[1][1] = 0;
    while (!q.empty()) {
        Point e = q.top();
        q.pop();
        int x = e.x, y = e.y, d = e.dist;
        
    }
}