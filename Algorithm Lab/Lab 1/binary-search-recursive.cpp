#include <iostream>

using namespace std;

int count;

// Recursive binary search
int binarySearch(int arr[], int l, int r, int key) {
    count++;
    if (r >= l) {
        count++;
        int mid = l + (r - l) / 2;

        count++;
        // If element is in the middle
        if (arr[mid] == key) {
            count++;
            return mid;
        }

        count++;
        // Search in the left subarray
        if (arr[mid] > key) {
            count++;
            return binarySearch(arr, l, mid - 1, key);
        }

        count++;
        // Search in right subarray
        return binarySearch(arr, mid + 1, r, key);
    }

    count++;
    // If not found, return -1
    return -1;
}

int main() {
    int n, key;

    count = 0;

    cout << "Enter the number of elements" << endl;
    cin >> n;

    int a[n];

    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter the element to be searched" << endl;
    cin >> key;

    int result = binarySearch(a, 0, n - 1, key);

    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }

    cout << "Step count: " << count << endl;

    return 0;
}
