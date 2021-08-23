#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
struct time {
    int h, m;
    time operator+(const time x) const {
        time tmp;
        tmp.m = (m + x.m) % 60;
        tmp.h = h + x.h + (m + x.m) / 60;
        return tmp;
    }
};


int main() {
    time t1, t2;
    cin >> t1.h >> t1.m;
    t2.h = 1;
    t2.m = 0;
    time sum;
    sum = t1 + t2;
    cout << sum.h << ' ' << sum.m;
    return 0;
}
