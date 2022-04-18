#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int m, i, h;
int val[N], ne[N];

void head(int x) {
    /*
    O.value <- x
      \/
    -> O ->
    |      /
    h :: O -> ...
    */
    val[i] = x;
    ne[i] = h;
    h = i ++ ;
}

void add(int k, int x) {
    /*
    O.value <- x
      \/
     -> O -/
     |    \/
    .. :: O -> O -> ...
    */
    val[i] = x;
    ne[i] = ne[k];
    ne[k] = i ++ ;
}

void del(int k) {
    /*
           ---------|
          /         \/
    .. -> O :: O :: O -> ...
    */
    ne[k] = ne[ne[k]];
}

int main() {
    int m;
    cin >> m;

    h = -1;
    i = 0;

    while (m -- ) {
        int k, x;
        char op;

        cin >> op;
        if (op == 'H') {
            cin >> x;
            head(x);
        } else if (op == 'D') {
            cin >> k;
            if (!k) h = ne[h];
            else del(k - 1);
        } else {
            cin >> k >> x;
            add(k - 1, x);
        }
    }

    for (int i = h; i != -1; i = ne[i]) cout << val[i] << ' ';
    puts("");

    return 0;
}