#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<int> st;
    string s;
    cin >> s;
    for (int i = 0; i < int(s.size()); i ++) {
        if (s[i] == '(') st.push(i);
        else {
            cout << st.top() << ' ' << i << endl;
            st.pop();
        }
    }
    return 0;
}
