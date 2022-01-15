#include <bits/stdc++.h>
using namespace std;

int counter;

int main()
{
    counter = 0;
    int n, c;
    cout << "enter the no. of boxes and capacity:\n";
    cin >> n >> c;
    int weight[1000], prices[1000], index[1000], density[1000];
    cout << "enter the weights:\n";
    for (int i = 0; i < n; i++, counter++)
    {
        counter++;
        index[i] = i + 1;
        cin >> weight[i];
    }
    cout << "enter the prices:\n";
    for (int i = 0; i < n; i++, counter++)
        cin >> prices[i];

    for (int i = 0; i < n; i++, c++)
    {
        counter++;
        density[i] = prices[i] / weight[i];
    }
    for (int i = 0; i < n; i++, counter++)
    {
        for (int j = 0; j < n - i - 1; j++, counter++)
        {
            counter++;
            if (density[j] > density[j + 1])
            {
                counter = counter + 3;
                swap(density[j], density[j + 1]);
                swap(index[j], index[j + 1]);
                swap(prices[j], prices[j + 1]);
                swap(weight[j], weight[j + 1]);
            }
        }
    }
    counter++;
    int k = 0, currWeight = 0;
    for (int i = 0; i < n; i++, counter++)
    {
        counter++;
        if (k < n && currWeight + weight[i] <= c)
        {
            counter++;
            currWeight += weight[i];
            counter++;
            k++;
        }
    }
    cout << "the boxes included are: ";
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    cout << "\n";
    cout << "the complexity is: " << counter;
}