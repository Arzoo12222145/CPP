#include <iostream>
#include <climits>
using namespace std;

#define INF 99999

void floydWarshall(int graph[][100], int v)
{
    int dist[v][v];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && (dist[i][k] + dist[k][j] < dist[i][j]))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int v;
    cout << "Enter the number of vertices: " << endl;
    cin >> v;

    int graph[v][100]; // Second dimension is set to a sufficiently large value

    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph, v);
}
