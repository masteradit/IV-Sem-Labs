#include <iostream>
using namespace std;

int Count = 0;

void traverse(int graph[][30], int n, int u, bool visited[])
{
    visited[u] = true;
    for (int v = 0; v < n; v++)
    {
        if (graph[u][v])
        {
            if (!visited[v])
                traverse(graph, n, v, visited);
        }
    }
}
bool isConnected(int a[][30], int n)
{
    bool *vis = new bool[n];
    for (int u; u < n; u++)
    {
        Count++; // For outer for loop
        for (int i = 0; i < n; i++)
        {
            Count++; // For inner for loop
            vis[i] = false;
            Count++;
        }
        Count++; // For false conditionn of inner for loop
        Count++;
        traverse(a, n, u, vis);
        for (int i = 0; i < n; i++)
        {
            Count++; // For inner for loop
            if (!vis[i])
            {
                Count++;
                Count++;
                return false;
            }
        }
        Count++; // For false conditionn of inner for loop
    } // For false condition of outer for loop
    Count++;
    return true;
}
int main()
{
    int n, g[30][30];
    cout << "Enter the number of vertex:\n";
    cin >> n;
    cout << "Fill the adjacency table:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    if (isConnected(g, n))
        cout << "The Graph is connected.";
    else
        cout << "The Graph is not connected.";
    cout << "\nNumber of steps : " << Count;
}