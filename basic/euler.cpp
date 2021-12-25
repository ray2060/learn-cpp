#include <iostream>

using namespace std;

const int N = 100;

int primes[N], phi[N], cnt;
bool st[N];

void get_eulers(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) {
            primes[cnt ++ ] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0) {
                phi[t] = phi[i] * primes[j];
                break;
            }
            phi[t] = phi[i] * (primes[j] - 1);
        }
    }
}

void phi_table(int n) {
    for (int i = 1; i <= n; i ++ ) phi[i] = i;
    for (int i = 2; i <= n; i ++ ) {
        if (phi[i] == i)
        	for (int j = i; j <= n; j += i) {
            	phi[j] = phi[j] / i * (i - 1);
        }
    }
}

int main() {
    phi_table(10);
    for (int i = 1; i <= 10; i ++ ) cout << phi[i] << " ";
    
    return 0;
}