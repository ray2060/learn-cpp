#include <cstdio>
#include <algorithm>

using namespace std;

// return number of swap operations
int selectionSort(int arr[], int n) {
    int sw = 0;
    for (int i = 0; i < n - 1; i++) {
        int minj = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minj]) minj = j;
        }
        if (i == minj) continue;
        swap(arr[i], arr[minj]);
        sw++;
    }
    
    return sw;
}

int main() {
    int n, sw;
    scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sw = selectionSort(arr, n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    // printf("\n%d\n", sw);
    return 0;
}
