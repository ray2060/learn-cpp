#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MID_NIGHT = 1440;
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i ++) {
        int h, m;
        cin >> h >> m;
        cout << MID_NIGHT - h * 60 - m << endl;
    }
    return 0;
}
