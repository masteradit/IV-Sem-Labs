#include <bits/stdc++.h>
using namespace std;
int c;
int main()
{
    c = 0;
    int v, e;
    cout << "enter the total vertixes and edges\n";
    cin >> v >> e;
    int **adj = new int *[v];
    for (int i = 0; i < v; i++, c++)
        adj[i] = new int[v];
    for (int i = 0; i < v; i++, c++)
    {
        for (int j = 0; j < v; j++, c++)
            adj[i][j] = 0;
    }
    cout << "enter the elements of the matrix:\n";
    for (int i = 0; i < e; i++, c++)
    {
        cout << "enter left and right of:" << i << "\n";
        int l, r;
        cin >> l >> r;
        adj[l][r] = 1;
    }
    c++;
    int indegree[1000] = {0};
    for (int j = 0; j < v; j++, c++)
    {
        for (int i = 0; i < v; i++, c++)
            indegree[j] += adj[i][j];
    }
    c++;
    queue<int> q;
    for (int i = 0; i < v; i++, c++)
    {
        c++;
        if (indegree[i] == 0)
        {
            c++;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        c++;
        c++;
        int curr = q.front();
        c++;
        q.pop();
        cout << curr << " ";
        for (int i = 0; i < v; i++, c++)
        {
            c++;
            if (adj[curr][i] == 1)
            {
                c++;
                c++;
                indegree[i]--;
                c++;
                if (indegree[i] == 0)
                {
                    c++;
                    q.push(i);
                }
            }
        }
    }
    cout << "\n";
    cout << "the complexity is: " << c;
    return 0;
}