#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int V = 1010;

vector<int> g[V];
bool st[V];
int e;

// 添加一条边a->b
void add(int a, int b) { g[a].push_back(b); }

void dfs(int u) {
    cout << u << " ";
    st[u] = true; // 点u已经被遍历过

    for (auto v : g[u])
        if (!st[v]) dfs(v);
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    cout << u << " ";
    st[u] = true; // 点u已经被遍历过
    
    while (!q.empty()) {
        int t = q.front();
        q.pop();

        for (auto v : g[t])
            if (!st[v]) {
                q.push(v);
                cout << v << " ";
                st[v] = true; // 点v已经被遍历过
            }
    }
}

int main() {
    cin >> e;
    int a, b;
    for (int i = 0; i < e; i ++ ) {
        cin >> a >> b;
        add(a, b);
    }
    
    dfs(0);
    puts("");
    
    memset(st, 0, sizeof st);
    bfs(0);
    puts("");
    
    return 0;
}
