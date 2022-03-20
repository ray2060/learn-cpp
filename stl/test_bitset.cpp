#include <iostream>
#include <bitset>

using namespace std;

const int V = 1e5;

std::bitset<V> g[V];

void add(int a, int b) { g[a][b] = 1; }

int main() {
    add(0, 1);
    add(0, 2);

    
    cout << g[0][1] << endl;
    cout << g[1][2] << endl;
    
    return 0;
}