#include <iostream>

using namespace std;

int count = 0;

int interpolationSearch(int arr[], int lo, int hi, int x)
{
    count++;
    int pos;
    count++; // For if statement
    if (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        count++;
        pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
        count++; // For if statement
        if (arr[pos] == x)
        {
            count++;
            return pos;
        }
        count++; // For if statement
        if (arr[pos] < x)
        {
            count++;
            return interpolationSearch(arr, pos + 1, hi, x);
        }
        count++; // For if statement
        if (arr[pos] > x)
        {
            count++;
            return interpolationSearch(arr, lo, pos - 1, x);
        }
    }
    return -1;
}
int main()
{
    int arr[20], n, index, x, i;
    cout << "enter the number of elements:";
    cin >> n;
    cout << "enter the elements:";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "enter the search element:";
    cin >> x;
    index = interpolationSearch(arr, 0, n - 1, x);
    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found.";

    cout << endl
         << "Count: " << count;
    return 0;
}