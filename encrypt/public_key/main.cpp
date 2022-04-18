#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

namespace ALGO {
    int qmi(int m, int k, int p) {
        int res = 1;
        while (k) {
            m = (long long)m * m % p;
            if (k & 1) res = (long long)res * m % p;
            k >>= 1;
        }
        return res;
    }
    
    int sqrt(int x) {
        int xhalf = 0.5f * x;
        int i = *(int*)&x;
        i = 0x5f375a86 - (i >> 1);
        x = *(int*)&i;
        x = x * (1.5f - xhalf * x * x);
        x = x * (1.5f - xhalf * x * x);
        x = x * (1.5f - xhalf * x * x);
    
        return 1 / x;
    }
    
    bool is_prime(int x) {
        for (int i = 2; i <= sqrt(x); i ++ ) {
            if (x % i == 0) return false;
        }
        return true;
    }
    
    int gcd(int a, int b) {
        int A = a, B = b, t;
        while (b) {
            t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    
    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
}

namespace PK{
    namespace GEN{
        int prime() {
            srand(time(0));
            for (int x = rand() % int(1e4) + int(1e4); true;  x += 3) {
                if (ALGO::is_prime(x)) {
                    return x;
                }
            }
        }
        
        int N(int p, int q) {
            return p * q;
        }
        
        int L(int p, int q) {
            return ALGO::lcm(p - 1, q - 1);
        }
        
        int E(int L) {
            for (int e = 2; true; e ++ ) {
                if (ALGO::gcd(e, L) == 1) {
                    return e;
                }
            }
        }
        
        int D(int E, int L) {
            for (int d = 2; true; d ++ ) {
                if (E * d % L == 1) {
                    return d;
                }
            }
        }
    }
    void gen(int &E, int &N, int &D) {
        int L, p, q;
        p = PK::GEN::prime();
        q = PK::GEN::prime();
        N = PK::GEN::N(p, q);
        L = PK::GEN::L(p, q);
        E = PK::GEN::E(L);
        D = PK::GEN::D(E, L);
    }
    
    int decode(int text, int D, int N) {
        return ALGO::qmi(text, D, N);
    }
    
    int encode(int text, int E, int N) {
        return ALGO::qmi(text, E, N);
    }
}

int main() {
    cout << "Welcome to RSA Lab!" << endl;
    bool running = true;
    while (running) {
        cout << "What are you going to do?" << endl;
        cout << "1.encode" << endl;
        cout << "2.decode" << endl;
        cout << "3.generate a key" << endl;
        cout << "4.exit" << endl;
        int x;
        cin >> x;
        int E, N, D, text;
        switch (x) {
            case 1:
                cout << "Your Public Key:" << endl;
                cin >> D >> N;
                cout << "The message: " << endl;
                cin >> text;
                cout << PK::encode(text, E, N) << endl;
                break;
            case 2:
                cout << "Your Private Key:" << endl;
                cin >> D >> N;
                cout << "The message: " << endl;
                cin >> text;
                cout << PK::decode(text, D, N) << endl;
                break;
            case 3:
                PK::gen(E, N, D);
                cout << "Public:" << E << ", " << N;
                cout << endl;
                cout << "Private:" << D << ", " << N;
                cout << endl;
                break;
            case 4:
                running = false;
                break;
            default:
                cout << "Error!" << endl;
                running = false;
                break;
        }
    }
}