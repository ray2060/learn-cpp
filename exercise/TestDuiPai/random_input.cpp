#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random(int n) {
    return (long long)rand() * rand() % n;
}
int main() {
    freopen("data.in", "w", stdout);
    srand((unsigned)time(0));
    cout << random(100000) << ' ' << random(100000);
    return 0;
}