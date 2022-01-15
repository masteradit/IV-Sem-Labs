#include <iostream>

using namespace std;

int count;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        count++; // For the for loop

        count++;
        int j = i - 1;

        count++;
        int key = arr[i];

        for (; j >= 0 && arr[j] > key; j--) {
            count++;

            count++;
            arr[j + 1] = arr[j];
        }
        count++;

        count++;
        arr[j + 1] = key;
    }
    count++; // For false condition of for loop
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

    insertionSort(a, n);

    cout << "Sorted array" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }

    cout << "Step count: " << count << endl;

    return 0;
}
