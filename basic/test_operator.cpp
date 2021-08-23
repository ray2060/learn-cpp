#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    cout << (num << 1) << endl; // 左移一位
    cout << (num << 2) << endl; // 左移两位
    int n;
    cin >> n;
    cout << (num << n) << endl; // 左移n位
    cout << (num >> 1) << endl; // 右移一位
    cout << (num >> 2) << endl; // 右移两位
    cout << (num >> n) << endl; // 右移n位
    return 0;
}