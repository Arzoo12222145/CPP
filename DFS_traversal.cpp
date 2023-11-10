#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int> > adj;

    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if(direction == false)
        {
            adj[v].push_back(u);
        }
    }

    void DFS1(int v, unordered_map<int, bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";

        for(int neighbor : adj[v])
        {
            if(!visited[neighbor])
            {
                DFS1(neighbor,visited);
            }
        }
    }

    void DFS(int start)
    {
        unordered_map<int, bool> visited;
        DFS1(start,visited);
    }

    void print()
    {
        for(auto i:adj)
        {
            cout << i.first << " => ";
            for(auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

};
int main()
{
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges: " << endl;
    cin >> m;

    graph g;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g.addEdge(u,v,0);
    }

    g.print();

    int b;
    cout << "Enter the node to start bfs: " << endl;
    cin >> b;

    g.DFS(b);


}
