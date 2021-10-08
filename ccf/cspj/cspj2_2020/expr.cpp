#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;
struct ex_c {
    int val = -1;
    char op = ' ';
};
char c = ' ';
ex_c expr[1000010];
int main() {
    int i = 1, mn = -1;
    while (i ++ ) {
        if (c == '\n') {
            break;
        }
        cin >> c;
        if (c == 'x') {
            int n = 0;
            do {
                n *= 10;
                n += c - 48;
                cin >> c;
            } while (c != ' ');
            expr[i - 1] = {n, ' '};
            mn = max(mn, n);
        }
        else {
            expr[i - 1] = {-1, c};
            cin >> c;
        }
    }
    int q;
    cin >> q;
    stack<int> st;
    while (q -- ) {
        int x[5000010];
        for (int i = 0; i < mn; i ++ ) cin >> x[i];
        for (int i = 0; i < size(expr); i ++ ) {
            if (expr[i].op != ' ') {
                if (expr[i].op == '!') {
                    int a;
                    a = st.top(); st.pop(); st.push(~a);
                }
                int a, b;
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                if (expr[i].op == '&') {
                    st.push(a & b);
                } else {
                    st.push(a | b);
                }
            } else {
                st.push(x[expr[i].val]);
            }
        }
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}