#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(' ');
        for(int i = 0; i < s.size(); i ++) {
            if (s[i] == '}' && st.top() == '{') {
                st.pop();
                continue;
            }
            if (s[i] == ']' && st.top() == '[') {
                st.pop();
                continue;
            }
            if (s[i] == ')' && st.top() == '(') {
                st.pop();
                continue;
            }
            if (s[i] == '}' && st.top() != '{') {
                return false;
            }
            if (s[i] == ']' && st.top() != '[') {
                return false;
            }
            if (s[i] == ')' && st.top() != '(') {
                return false;
            }
            st.push(s[i]);
        }
        return st.size() == 1;
    }
};
