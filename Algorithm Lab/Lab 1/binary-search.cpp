#include <iostream>

using namespace std;

int count;

// Iterative binary search
int binarySearch(int arr[], int l, int r, int key) {
    count++;
    while (l <= r) {
        int m = l + (r - l) / 2;
        count++;

        count++;
        // If key is at m index
        if (arr[m] == key) {
            count++;
            return m;
        }

        count++;
        // If key is greater than mth element
        if (arr[m] < key) {
            count++;
            l = m + 1;
        }

        count++;
        // If key is smaller than mth element
        if (arr[m] > key) {
            count++;
            r = m - 1;
        }
    }
    count++;

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
