#include <iostream>
#include <climits>
using namespace std;

#define N 4
#define I INT_MAX

int count = 0;

void printPath(int path[][N], int v, int u)
{
    if (path[v][u] == v)
    {
        count++;
        return;
    }
    printPath(path, v, path[v][u]);
    cout << path[v][u] << " ";
}
void printSolution(int cost[N][N], int path[N][N])
{
    for (int v = 0; v < N; v++)
    {
        count++;
        for (int u = 0; u < N; u++)
        {
            count++;
            if (u != v && path[v][u] != -1)
            {
                count++;
                cout << "The shortest path from " << v << "<<" << u << " is (" << v << " ";
                printPath(path, v, u);
                cout << u << ")" << endl;
            }
        }
    }
}
void floydWarshall(int adjMatrix[][N])
{
    int cost[N][N], path[N][N];
    for (int v = 0; v < N; v++)
    {
        count++;
        for (int u = 0; u < N; u++)
        {
            count++;
            cost[v][u] = adjMatrix[v][u];
            if (v == u)
            {
                count++;
                path[v][u] = 0;
            }

            else if (cost[v][u] != INT_MAX)
            {
                count++;
                path[v][u] = v;
            }
            else
            {
                count++;
                path[v][u] = -1;
            }
        }
    }
    for (int k = 0; k < N; k++)
    {
        count++;
        for (int v = 0; v < N; v++)
        {
            count++;
            for (int u = 0; u < N; u++)
            {
                count++;
                if (cost[v][k] != INT_MAX && cost[k][u] != INT_MAX && cost[v][k] + cost[k][u] < cost[v][u])
                {
                    count++;
                    cost[v][u] = cost[v][k] + cost[k][u];
                    path[v][u] = path[k][u];
                }
            }
            if (cost[v][v] < 0)
            {
                count++;
                cout << "Negative-weight cycle found!!";
                return;
            }
        }
    }
    printSolution(cost, path);
}
int main()
{
    int adjMatrix[N][N] =
        {
            {1, 0, -2, I},
            {I, 1, 3, I},
            {3, I, 0, 2},
            {0, -1, -2, 0}};
    floydWarshall(adjMatrix);
    return 0;
}
