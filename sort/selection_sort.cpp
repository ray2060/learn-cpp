#include <cstdio>

// return number of swap operations
int selectionSort(int arr[], int n) {
    int sw = 0;
    for (int i = 0; i < n - 1; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[minj]) minj = j;
        }
        if (i == minj) continue;
        int t;
        t = arr[i];
        arr[i] = arr[minj];
        arr[minj] = t;
        sw++;
    }
    
    return sw;
}

int main() {
    int arr[100], n, sw;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sw = selectionSort(arr, n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    // printf("\n%d\n", sw);
    return 0;
}
