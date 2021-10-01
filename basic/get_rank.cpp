#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct tNode {
    int data, rank, index;
};
int N;
tNode a[10001];
bool cmpData (tNode x, tNode y) {
    return x.data < y.data;
}

bool cmpIndex (tNode x, tNode y) {
    return x.index < y.index;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i ++) cin >> a[i].data, a[i].index = i;
    sort(a, a + N, cmpData);
    for (int i = 0; i < N; i ++) a[i].rank = i + 1;
    sort(a, a + N, cmpIndex);
    for (int i = 0; i < N; i ++) cout << a[i].rank << ' ';
    cout << endl;
    return 0;
}
