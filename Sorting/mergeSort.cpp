#include <iostream>
using namespace std;

// Merge two sorted parts of the array
void merge(int arr[], int low, int mid, int high) {
    int temp[high - low + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from the left part
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from the right part
    while (j <= high) {
        temp[k++] = arr[j++];
    }

    // Copy sorted elements back into the original array
    for (int x = 0; x < k; x++) {
        arr[low + x] = temp[x];
    }
}

// Divide the array into smaller parts
void mergeSort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main() {
    int arr[] = {5, 2, 8, 1, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}