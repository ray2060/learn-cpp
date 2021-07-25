#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct tNode {
    int val, next;
};
int N, M;
tNode a[200002];
int fa = 0;
tNode adj[5002];

void insert(int u, int v) {
    a[++fa].val = v;
    a[fa].next = adj[u].next;
    adj[u].next = fa;
    adj[u].val ++;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i ++ ) {
        int p, q;
        cin >> p >> q;
        insert(p, q);
        insert(q, p);
    }
    for (int i = 1; i <= N; i ++ ) {
        cout << adj[i].val << ' ';
        for (int j = adj[i].next; j > 0; j = a[j].next) cout << a[j].val << ' ';
        cout << endl;
    }
    return 0;
}
