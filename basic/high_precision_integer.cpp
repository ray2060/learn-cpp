#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXD = 10010;

string get_zr(const int n) {
    string s;
    for (int i = 0; i < n; i ++ ) {
        s[i] = '0';
    }
    return s;
}

struct high_precision_integer {
    short val[MAXD];
    int len;
    
    void _reverse_vals() {
        for (int i = 0, j = MAXD; i < j; i ++ , j -- ) swap(val[i], val[j]);
    }
    
    void read(string s) {
        memset(val, 0, MAXD * sizeof(short int));
        len = s.size();
        for (int i = 0; i < len; i ++ ) {
            val[i] = s[i] - 48;
        }
        _reverse_vals();
    }
    
    void output() {
        _reverse_vals();
        bool flag = false;
        for (int i = 0; i < MAXD; i ++ ) {
            if (flag || val[i] != 0) {
                cout << int(val[i]);
                flag = true;
            }
        }
        _reverse_vals();
        cout << endl;
    }
    
    high_precision_integer operator+(const high_precision_integer x) const {
        int c[MAXD];
        int len_ans;
        len_ans = max(len, x.len);
        high_precision_integer ans;
        ans.len = len_ans;
        memset(c, 0, MAXD * sizeof(int));
        ans.read(get_zr(MAXD));
        for (int i = 0; i <= len_ans; i ++ ) {
            cout << i << endl;
            ans.val[i] = val[i] + x.val[i] + c[i];
            if (ans.val[i] > 9) {
                c[i + 1] = 1;
                ans.val[i] -= 10;
            }
        }
        if (ans.val[len_ans] != 0) ans.len += 1;
        return ans;
    }
    
    high_precision_integer operator+(const int x) const {
        int c[MAXD];
        int len_ans;
        len_ans = max(int(len), 1);
        high_precision_integer ans;
        memset(c, 0, MAXD * sizeof(int));
        ans.read(get_zr(MAXD));
        ans.len = len_ans;
        for (int i = 0; i <= len_ans; i ++ ){
            if (!i) ans.val[i] = val[i] + x + c[i];
            else ans.val[i] = val[i] + c[i];
            if (ans.val[i] > 9) {
                c[i + 1] = 1;
                ans.val[i] -= 10;
            }
        }
        if (ans.val[len_ans] != 0) ans.len += 1;
        return ans;
    }
    
    high_precision_integer operator*(const high_precision_integer x) const {
        int c[MAXD];
        int len_ans;
        len_ans = max(len, x.len);
        high_precision_integer ans;
        memset(c, 0, MAXD * sizeof(high_precision_integer));
        ans.read(get_zr(MAXD));
        ans.len = len_ans;
        for (int i = 0; i <= x.len; i ++) {
            for (int j = 0; j <= len; j ++ ) {
                int t;
                t = val[j] * x.val[i] + c[j];
                if (t > 9) {
                    c[j + 1] = t / 10;
                    t %= 10;
                }
                ans = ans + (t * pow(10, i));
            }
        }
        return ans;
    }
};

int main() {
    string a, b;
    cin >> a >> b;
    high_precision_integer i1, i2;
    i1.read(a);
    i2.read(b);
    (i1 * i2).output();
    return 0;
}
