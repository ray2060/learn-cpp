#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 10, P = 1e6 + 3;

typedef long long LL;

int n;

struct T{
    int a[6];
    T {}
} h[P];
T e[N];
int ne[N];

int get_hash(T x) {
    int sum = 0, mul = 1;
    for (int i = 0; i < 6; i ++ ) {
        sum += ((LL)x.a[i] + sum) % P;
        mul = ((LL)x.a[i] * mul) % P;
    }
    return ((LL)sum + mul) % P;
}

bool check_eq(T a, T b) {
    for (int i = 0; i < 6; i ++ ) {
        bool flag = true;
        for (int j = 0; j < 6; j ++ ) {
            if (a.a[(i + j) % 6] != b.a[j]) flag = false;
        }
        if (flag) return true;
    }
    reverse(a, a + 6);
    for (int i = 0; i < 6; i ++ ) {
        bool flag = true;
        for (int j = 0; j < 6; j ++ ) {
            if (a.a[(i + j) % 6] != b.a[j]) flag = false;
        }
        if (flag) return true;
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        
    }
}