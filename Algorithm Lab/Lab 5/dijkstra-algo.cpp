#include <iostream>
#include <climits>
using namespace std;
int counter = 0;
int minDistance(int shortest[], bool visited[], int V)
{
    int minIndex = -1;
    counter++;
    for (int i = 0; i < V; i++)
    {
        counter++;
        if (minIndex == -1)
        {
            if (!visited[i])
            {
                minIndex = i;
                counter++;
            }
            counter++;
        }
        else if (!visited[i] && shortest[i] < shortest[minIndex])
        {
            minIndex = i;
            counter++;
        }
        counter++;
    }
    counter++;
    counter++;
    return minIndex;
}
void dijkstra(int a[][100], int V, int source)
{
    bool visited[100];
    counter++;
    int shortest[100], temp = V, u;
    counter++;
    for (int i = 0; i < V; i++)
    {
        counter++;
        visited[i] = false;
        counter++;
    }
    counter++;
    for (int i = 0; i < V; i++)
    {
        counter++;
        shortest[i] = INT_MAX;
        counter++;
    }
    counter++;
    shortest[source] = 0;
    counter++;
    while (temp != 0)
    {
        counter++;
        u = minDistance(shortest, visited, V);
        counter++;
        for (int i = 0; i < V; i++)
        {
            counter++;
            if (a[u][i] != -1 && !visited[i])
            {
                if (shortest[u] + a[u][i] < shortest[i])
                {
                    shortest[i] = shortest[u] + a[u][i];
                    counter++;
                }
                counter++;
            }
            counter++;
        }
        counter++;
        visited[u] = true;
        counter++;
        temp--;
        counter++;
    }
    cout << "\nThe shortest distance from source to nodes are" << endl;
    cout << "Vertex Distance" << endl;
    for (int i = 0; i < V; i++)
        cout << (i + 1) << " " << shortest[i] << endl;
    cout << "\n\nNumber of steps : " << counter;
}
int main()
{
    int v, source;
    cout << "\nEnter the number of vertices" << endl;
    cin >> v;
    int a[100][100];
    cout << "\nEnter the adjacency matrix (-1 if not adjacent)" << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "\nEnter the source" << endl;
    cin >> source;
    dijkstra(a, v, source - 1);
    counter++;
    return 0;
}