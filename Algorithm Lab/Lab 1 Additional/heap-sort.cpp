#include <iostream>
using namespace std;

int Count = 0;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Count++; //for the for loop
        Count++; //for function call
        heapify(arr, n, i);
    }
    Count++; // for the false condition of the for loop
    for (int i = n - 1; i > 0; i--)
    {
        Count++; //for the for loop
        int temp = arr[0];
        Count++; //for the assignment operation
        arr[0] = arr[i];
        Count++; //for the assignment operation
        arr[i] = temp;
        Count++; //for the assignment operation
        Count++; //for the function call
        heapify(arr, i, 0);
    }
}
int main()
{
    int a[20], n, i;
    cout << "enter the size\n";
    cin >> n;
    cout << "Enter the elements\n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    heapSort(a, n);
    cout << "The sorted  array is \n";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\nNumber of step : " << Count;
    return 0;
}