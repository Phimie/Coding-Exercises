#include <iostream>
using namespace std;

int Fill_array(double a[], int max);
void Show_array(double a[], int n);
void Reverse_array(double a[], int n);

int main() {
    const int MAX = 100;
    double arr[MAX];
    int n = Fill_array(arr, MAX);
    
    Show_array(arr, n);
    
    Reverse_array(arr, n);
    Show_array(arr, n);
    
    Reverse_array(arr + 1, n - 2);
    Show_array(arr, n);
    
    return 0;
}

int Fill_array(double a[], int max) {
    cout << "Enter up to " << max << " numbers:\n";
    int count = 0;
    double value;
    while (count < max && cin >> value) {
        a[count++] = value;
    }
    return count;
}

void Show_array(double a[], int n) {
    cout << "Array elements:\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << '\n';
    }
}

void Reverse_array(double a[], int n) {
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        double temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
