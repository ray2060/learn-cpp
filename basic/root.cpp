#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string root(string s) {
    if (s.size() == 1) return s;
    int m;
    for (int i = 0; i < s.size(); i ++) m += s[i] - 48;
    stringstream st;
    st << m;
    string t;
    st >> t;
    return root(t);
}

int main() {
    string s;
    cin >> s;
    cout << root(s);
    return 0;
}
