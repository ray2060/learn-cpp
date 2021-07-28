#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct time{
    int hi, mi;
};
int main() {
    int N;
    cin >> N;
    time arr[1010];
    for (int i = 0; i < N; i ++ ) cin >> arr[i].hi >> arr[i].mi;
    int sum = 0;
    for (int i = 0; i < N; i ++ ) sum += arr[i].hi * 60 + arr[i].mi;
    int sum_h, sum_m;
    sum_h = sum / 60;
    sum_m = sum % 60;
    cout << sum_h << ' ' << sum_m;
    return 0;
}
