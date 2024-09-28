#include <iostream>

using namespace std;

void input(int a[], int &n) {
    for (int i = 0; i < n; i++)
    {
        cout << "a["<<i<<"]= ";
        cin >> a[i];
    }
}

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void output(int a[], int &n) {
    for (int i = 0; i < n; i++)
    {
        cout  << a[i] << " ";
    }
}


int main() {
    
    int n;
    int a[100];
    cout << " Nhap so luong phan tu: ";
    cin >> n;

    input(a, n);
    bubble_sort(a, n);
    output(a, n);

   

	return 0;
}