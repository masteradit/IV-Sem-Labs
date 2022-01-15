#include <iostream>
using namespace std;

void minmax(int arr[], int l, int r, int &min, int &max)
{
    if (r - l <= 1)
    {
        if (arr[l] > arr[r])
        {
            if (min > arr[r])
                min = arr[r];
            if (max < arr[l])
                max = arr[l];
        }
        else
        {
            if (min > arr[l])
                min = arr[l];
            if (max < arr[l])
                max = arr[r];
        }
    }
    else
    {
        minmax(arr, l, (l + r) / 2, min, max);
        minmax(arr, (l + r) / 2, r, min, max);
    }
}
int main()
{
    int n;
    cout << "Enter size of array\n";
    cin >> n;
    cout << "Enter elements of array\n";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = 0;
    int min = 99999;
    minmax(arr, 0, n - 1, min, max);
    cout << "The minimum element is " << min << endl;
    cout << "The maximum element is " << max << endl;
    return 0;
}
