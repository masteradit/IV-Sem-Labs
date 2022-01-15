#include <bits/stdc++.h>
using namespace std;
int counter;
int main()
{
    counter = 0;
    int n, c;
    cout << "enter the no. of boxes and total capacity\n";
    cin >> n >> c;
    int weight[1000], index[1000];
    cout << "enter the weights of boxes: \n";
    for (int i = 0; i < n; i++, counter++)
    {
        cin >> weight[i];
        counter++;
        index[i] = i + 1;
    }
    for (int i = 0; i < n; i++, counter++)
    {
        for (int j = 0; j < n - i - 1; j++, counter++)
        {
            counter++;
            if (weight[j] > weight[j + 1])
            {
                counter = counter + 3;
                swap(weight[j], weight[j + 1]);
                swap(index[j], index[j + 1]);
            }
        }
    }
    counter++;
    int k = 0, currWeight = 0;
    for (int i = 0; i < n; i++, counter++)
    {
        counter++;
        if (currWeight + weight[i] <= c)
        {
            counter++;
            currWeight += weight[i];
            counter++;
            k++;
        }
    }
    cout << "boxes included are: ";
    for (int i = 0; i < k; i++)
    {
        cout << index[i] << " ";
    }
    cout << endl;
    cout << "Time complexity is: " << counter;
    return 0;
}