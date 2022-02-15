#include <iostream>

using namespace std;

int get_d(int x, int d) {
    switch (d) {
        case 1:
            return x / 100;
        case 2:
            return x % 100 / 10;
        case 3:
            return x % 10;
    }
}

void qsort(int a[],int b,int c) {
    int k, i = b - 1, j = c + 1;

    if(b >= c){
        return;
    }

    k = a[(b + c) / 2];
    while (i < j) {
        do {
            i ++ ;
        } while (a[i] < k);
        do {
            j -- ;
        } while (a[j] > k);
        if (i < j) swap(a[i], a[j]);
    }

    qsort(a, b, j);
    qsort(a, j + 1, c);

}

bool check(int i) {
    int b = i * 2;
    int c = i * 3;
    int a1 = get_d(i, 1);
    int a2 = get_d(i, 2);
    int a3 = get_d(i, 3);
    int b1 = get_d(b, 1);
    int b2 = get_d(b, 2);
    int b3 = get_d(b, 3);
    int c1 = get_d(c, 1);
    int c2 = get_d(c, 2);
    int c3 = get_d(c, 3);
    int a[9] = {a1, a2, a3, b1, b2, b3, c1, c2, c3};
    qsort(a, 0, 8);
    return a[0] == 1 && 
            a[1] == 2 && 
            a[2] == 3 && 
            a[3] == 4 && 
            a[4] == 5 && 
            a[5] == 6 && 
            a[6] == 7 && 
            a[7] == 8 && 
            a[8] == 9 ? true : false;
}

int main() {
    for (int i = 123; i <= 329; i ++ ) {
        if (check(i)) {
            cout << i << ' ' << i * 2 << ' ' << i * 3 << endl;
        }
    }
    return 0;
}