#include <iostream>
#include <bitset>

using namespace std;

const int N = 10;

// init
bitset<N> bs (string("0011"));

int main() {
    bs.flip();
    cout << bs << endl;
    
    bs.reset();
    cout << bs << endl;
    
    bs.set(2);
    cout << bs << endl;
       
    bitset<N> bs1;
    bs1.set(3, 1);
    bs ^= bs1;
    cout << bs << endl;
    
    cout << bs.test(2) << endl;
}