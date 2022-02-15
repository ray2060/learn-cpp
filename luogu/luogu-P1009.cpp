#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXD = 10010;

struct HPI {
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
    
    void convert(int x) {
        string s;
        int i = 0;
        while (x != 0) {
            s[i ++ ] = x % 10;
            x /= 10;
        }
        read(s);
    }
    
    void zero() {
        read("0");
    }
    
    HPI operator+(const HPI x) const {
        int c[MAXD];
        int len_ans;
        len_ans = max(len, x.len);
        HPI ans;
        ans.len = len_ans;
        memset(c, 0, MAXD * sizeof(int));
        ans.zero();
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
    
    HPI operator+(const int x) const {
        int c[MAXD];
        int len_ans;
        len_ans = max(int(len), 1);
        HPI ans;
        memset(c, 0, MAXD * sizeof(int));
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
    
    HPI operator*(const HPI x) const {
        int c[MAXD];
        int len_ans;
        len_ans = max(len, x.len);
        HPI ans;
        memset(c, 0, MAXD * sizeof(HPI));
        ans.zero();
        ans.len = len_ans;
        for (int i = 0; i <= x.len; i ++) {
            for (int j = 0; j <= len; j ++ ) {
                int t;
                t = val[j] * x.val[i] + c[j];
                if (t > 9) {
                    c[j + 1] = t / 10;
                    t %= 10;
                }
                ans = ans + int(t * pow(10, i));
            }
        }
        return ans;
    }
    
};

HPI fact(int x) {
    HPI y;
    y.convert(x);
    HPI zr;
    zr.zero();
    zr = zr + 1;
    HPI ans;
    ans.zero();
    ans = ans + 1;
    for (int i = 1; i <= x; i ++, zr = zr + 1) {
        ans = ans * zr;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    HPI ans;
    ans.zero();
    ans = ans + 1;
    for (int i = 1; i < n; i ++ ) {
        ans = ans + fact(i);
    }
    ans.output();
    return 0;
}
