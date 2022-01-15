#include <bits/stdc++.h>

using namespace std;

void BFS(int A[10][10], int a, int b, int &x)
{
    queue<int> q;
    x++;
    int z;
    bool visited[a];
    for (int i = 0; i < b; i++)
    {
        x++;
        visited[i] = false;
    }
    x++;
    q.push(0);
    while (!q.empty())
    {
        z = q.front();
        q.pop();
        x++;
        if (!visited[z])
        {
            cout << z << " ";
            visited[z] = true;
            x++;
        }
        for (int i = 0; i < a; i++)
        {
            x++;
            if (A[z][i] && visited[i] == false)
            {
                q.push(i);
                x++;
            }
        }
    }
}
int main()
{
    int A[10][10], n, m, x, co = 0;
    ;
    cout << "enter no. of vertice\n";
    cin >> n;
    co++;
    cout << "enter number of edges\n";
    cin >> m;
    co++;
    for (int i = 0; i < n; i++)
    {
        co++;
        {
            for (int j = 0; j < n; j++)
            {
                A[i][j] = 0;
                co++;
            }
        }
    }
    co++;
    int p, q;
    for (int i = 1; i <= m; i++)
    {
        cout << "Enter Source: ";

        cin >> p;
        co++;
        cout << "Enter destination: ";
        cin >> q;
        co++;
        A[p][q] = 1;
    }
    BFS(A, n, m, co);
    co++;
    cout << endl
         << "No of counts: " << co << endl;
}