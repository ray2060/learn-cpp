#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int bubbleSort(int arr[], int n) {
    int sw;
    bool madeAswap;
    for (int i = n - 1; i > 0; i --) {
        madeAswap = false;
        for (int j = 0; j < i; j ++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                sw ++;
                madeAswap = true;
            }
        }
        if (!madeAswap) break;
    }
    return sw;
}

int main() {
    int n, sw;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i ++) cin >> arr[i];
    sw = bubbleSort(arr, n);
    for (int i = 0; i < n; i ++) cout << arr[i] << ' ';
    // cout << sw;
    return 0;
}
