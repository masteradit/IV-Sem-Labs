#include <bits/stdc++.h>
using namespace std;
int c;
int findMinVertex(int *distance, bool *visited, int v)
{
    c++;
    int minVal = INT_MAX, minIndex;
    for (int i = 0; i < v; i++, c++)
    {
        c++;
        if (!visited[i] && distance[i] < minVal)
        {
            c++;
            minIndex = i;
            c++;
            minVal = distance[i];
        }
    }

    c++;
    return minIndex;
}
int main()
{
    int v, e;
    cout << "enter the vertices and edges: \n";
    cin >> v >> e;
    cout << endl;
    int **adj = new int *[v];
    for (int i = 0; i < v; i++)
        adj[i] = new int[v];
    for (int i = 0; i < v; i++, c++)
        for (int j = 0; j < v; j++, c++)
        {
            c++;
            adj[i][j] = 0;
        }
    cout << "enter the elements and the weights";
    for (int i = 0; i < e; i++, c++)
    {
        int l, r, w;
        cin >> l >> r >> w;
        c++;
        adj[l][r] = w;
        c++;
        adj[r][l] = w;
    }
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++, c++)
    {
        c++;
        visited[i] = false;
    }
    int *distance = new int[v];
    int *parent = new int[v];
    for (int i = 1; i < v; i++, c++)
    {
        c++;
        distance[i] = INT_MAX;
    }
    c++;
    distance[0] = 0;
    for (int i = 0; i < v - 1; i++, c++)
    {
        c++;
        int curr = findMinVertex(distance, visited, v);
        c++;
        visited[curr] = true;
        for (int j = 0; j < v; j++, c++)
        {
            c++;
            if (!visited[j] && adj[curr][j] != 0)
            {
                c++;
                if (distance[j] > adj[curr][j])
                {
                    c++;
                    distance[j] = adj[curr][j];
                    c++;
                    parent[j] = curr;
                }
            }
        }
    }
    for (int i = 1; i < v; i++)
        cout << min(parent[i], i) << " -> " << max(parent[i], i) << " : " << distance[i] << "\n";
    cout << "\n";
    cout << "the complecity is: " << c;
    return 0;
}