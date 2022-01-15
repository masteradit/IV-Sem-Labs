#include <bits/stdc++.h>

using namespace std;
void DFS(int A[10][10], int a, int b, int &c)
{
    stack<int> s;
    c++;
    int z;
    bool visited[a];
    for (int i = 0; i < a; i++)
    {
        c++;
        visited[i] = false;
    }
    c++;
    s.push(0);
    while (!s.empty())
    {
        z = s.top();
        s.pop();
        c++;
        if (!visited[z])
        {
            cout << z << " ";
            visited[z] = true;
            c++;
        }
        for (int i = 0; i < a; i++)
        {
            c++;
            if (A[z][i] && visited[i] == false)
            {
                s.push(i);
                c++;
            }
        }
    }
}
int main()
{
    int A[10][10], n, m, x, co = 0;
    ;
    cout << "Enter no. of the vertices\n"
         << endl;
    cin >> n;
    co++;
    cout << "Enter number of the edges\n"
         << endl;
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
        cout << "Enter Source: " << endl;
        cin >> p;
        co++;
        cout << "Enter destination: " << endl;
        cin >> q;
        co++;
        A[p][q] = 1;
    }
    DFS(A, n, m, co);
    co++;
    cout << endl
         << "\nNo of counts:" << co << endl;
}