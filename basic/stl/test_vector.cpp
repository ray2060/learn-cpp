#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int nothing;
    cin >> nothing;
    vector<int> v;
    v.push_back(8); // 8
    v.push_back(10); // 8, 10
    v.pop_back(); // 8
    v.insert(0, 7); // 7, 8
    v.erase(0); // 8
    v.clear(); // none
    cout << v.size() << endl;
    for(int i = 10; i >= 0; i --) {
        v.push_back(i);
    } // 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    cout << v.front() << endl;
    cout << v.back() << endl;
    sort(v.begin(), v.end());
    for (long long unsigned int i = 0; i < v.size(); i ++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}
