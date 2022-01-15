#include <iostream>
#include <climits>
using namespace std;

int count = 0;

int matrixChainMultiplication(int dims[], int i, int j)
{
    if (j <= i + 1)
    {
        count++;
        return 0;
    }
    int min = INT_MAX;
    for (int k = i + 1; k <= j - 1; k++)
    {
        count++;
        int cost = matrixChainMultiplication(dims, i, k);
        cost += matrixChainMultiplication(dims, k, j);
        cost += dims[i] * dims[k] * dims[j];
        if (cost < min)
        {
            count++;
            min = cost;
        }
    }
    return min;
}
int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;
    int dims[n];
    cout << "Enter the sequence of matrices: ";
    for (int i = 0; i < n; i++)
    {
        count++;
        cin >> dims[i];
    }
    cout << "The minimum cost is " << matrixChainMultiplication(dims, 0, n - 1);
    cout << "\nStep count: " << count;
    return 0;
}