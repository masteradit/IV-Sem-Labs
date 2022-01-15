#include <iostream>

using namespace std;

int count;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        count++; // For outer for loop
        for (int j = 0; j < n-i-1; j++) {
            count++; // For inner for loop

            count++; // For if condition
            if (arr[j] > arr[j+1]) {
                count++;
                int temp = arr[j];
                count++;
                arr[j] = arr[j + 1];
                count++;
                arr[j + 1] = temp;
            }
        }
        count++; // For false case of inner for loop
    }
    count++; // For false case of outer for loop
}

int main() {
    int n;

    count = 0;

    cout << "Enter the number of elements" << endl;
    cin >> n;

    int a[n];

    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bubbleSort(a, n);

    cout << "Sorted array" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }

    cout << "Step count: " << count << endl;

    return 0;
}
