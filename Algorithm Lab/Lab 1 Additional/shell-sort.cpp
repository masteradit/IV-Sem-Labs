#include <iostream>
using namespace std;

int count = 0;

int shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        count++;
        for (int i = gap; i < n; i += 1)
        {
            count++;
            int temp = arr[i];
            count++;
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
                count++;
            }
            count++;
            arr[j] = temp;
            count++;
        }
        count++;
    }
    count++;
    return 0;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[20], i, n;
    cout << "enter the number of elements:";
    cin >> n;
    cout << "enter the elements:";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Array before sorting: \n";
    printArray(arr, n);
    shellSort(arr, n);
    cout << "\nArray after sorting: \n";
    printArray(arr, n);
    cout << endl
         << "Count: " << count;
    return 0;
}