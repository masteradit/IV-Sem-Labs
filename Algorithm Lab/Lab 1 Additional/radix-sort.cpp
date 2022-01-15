#include <iostream>
using namespace std;

int count = 0;

void radsort(int A[], int n)
{
    int temp;
    int bucket[10][20];
    int buck_count[10];
    int i, k, j, r, np = 0, divisor = 1;
    count++; //for initialization
    int largest, pass_no;
    largest = A[0];
    for (i = 1; i < n; i++)
    {
        count++; //for the for loop
        count++; //for the if condition
        if (A[i] > largest)
        {
            largest = A[i];
            count++; //for the assignment operation
        }
    }
    count++; //for the false condition of for loop
    while (largest > 0)
    {
        count++; //for the while loop
        np++;
        count++; //for the increment operation;
        largest = largest / 10;
        count++; //for the assignment operation
    }
    count++; //for the false condition of the while loop
    for (pass_no = 0; pass_no < np; pass_no++)
    {
        count++; //for the for loop
        for (k = 0; k < 10; k++)
        {
            count++; //for the for loop
            buck_count[k] = 0;
            count++; //for the assignment operation
        }
        count++; //for the false condition of the for loop
        for (i = 0; i < n; i++)
        {
            count++; //for the for loop
            r = (A[i] / divisor) % 10;
            count++; //for the assignment operation
            bucket[r][buck_count[r]++] = A[i];
            count++; //for the assignment operation
        }
        count++; //for the false condition of the for loop
        i = 0;
        count++; //for the assignment operation
        for (k = 0; k < 10; k++)
        {
            count++; //for the for loop
            for (j = 0; j < buck_count[k]; j++)
            {
                count++; //for the for loop
                A[i++] = bucket[k][j];
                count++; //for the assignment operation
            }
            count++; //for the false condition of the for loop
        }
        count++; //for the false condition of the for loop
        divisor = divisor * 10;
        count++; //for the assignment operation
    }
    count++; //for the false condition of the for loop
}
int main()
{
    int a[20], n, i, j;
    cout << "enter the size\n";
    cin >> n;
    cout << "Enter the elements\n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    radsort(a, n);
    cout << "The sorted  array is \n";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\nNumber of steps : " << count;
    return 0;
}