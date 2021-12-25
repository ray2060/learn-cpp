#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    
string s = "192.168.0.1:8080";
smatch m;

regex e1("(\\d+)[.](\\d+)[.](\\d+)[.](\\d+):(\\d+)");		
if (regex_match(s, m, e1)) {
    int d1 = stoi(m.str(1));
    if (m.str(1)[0] == '0' && d1 != 0 || d1 > 255)
        cout << "ERR" << endl;
    else
        cout << d1 << endl;
}

s = "Feel free to reach me at "
    "ray@pythoner.work, or "
    "ray2060@qq.com.";

regex e2("REACH (ME)", regex_constants::icase);
if (regex_search(s, m, e2)) {
    cout << m.str(0) << endl;
    cout << m.str(1) << endl;
}
 
regex e3("(\\w+)@(\\w+[.]\\w+)");
sregex_iterator it(s.cbegin(), s.cend(), e3);
sregex_iterator end;
while (it != end) {
    cout << "Matched: " << it->str(0) << endl;
    cout << "User name: " << it->str(1) << endl;
    cout << "Domain: " << it->str(2) <<endl;
    it ++ ;
}
 
regex e4("\\w{5,}");
string new_s = regex_replace(s, e4, "[$&]");
cout << new_s << endl;

}