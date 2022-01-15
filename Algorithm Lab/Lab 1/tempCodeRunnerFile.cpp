#include <iostream>

using namespace std;

int count;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        count++; // For outer for loop

        count++;
        int min_idx = i;

        for (int j = i+1; j < n; j++) {
            count++; // For inner for loop

            count++;
            if (arr[j] < arr[min_idx]) {
                count++;
                min_idx = j;
            }
        }
        count++; // For false condition of inner for loop

        // Swap the found minimum element with the first element
        count++;
        int temp = arr[min_idx];
        count++;
        arr[min_idx] = arr[i];
        count++;
        arr[i] = temp;
    }
    count++; // For false condition of outer for loop
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

    selectionSort(a, n);

    cout << "Sorted array" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }

    cout << "Step count: " << count << endl;

    return 0;
}
