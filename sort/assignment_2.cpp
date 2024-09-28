#include <iostream>
using namespace std;

// H�m heapify m?t c�y con
void heapify(int arr[], int n, int i) {
    int largest = i; // Kh?i t?o largest l� g?c
    int left = 2 * i + 1; // Con tr�i
    int right = 2 * i + 2; // Con ph?i

    // N?u con tr�i l?n h?n g?c
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // N?u con ph?i l?n h?n largest hi?n t?i
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // N?u largest kh�ng ph?i l� g?c
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Heapify l?i c�y con b? ?nh h??ng
        heapify(arr, n, largest);
    }
}

// H�m th?c hi?n heap sort
void heapSort(int arr[], int n) {
    // X�y d?ng heap (s?p x?p l?i m?ng)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Tr�ch xu?t t?ng ph?n t? m?t t? heap
    for (int i = n - 1; i > 0; i--) {
        // Di chuy?n ph?n t? g?c hi?n t?i ??n cu?i
        swap(arr[0], arr[i]);

        // G?i heapify tr�n heap r�t g?n
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[10000];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
