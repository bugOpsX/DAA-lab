#include <iostream>
#include <limits>

using namespace std;

int main()
{
    const int MAX = 100;
    int graph[MAX][MAX];
    int key[MAX];
    int parent[MAX];
    bool inMST[MAX];

    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0 || n > MAX)
    {
        cout << "Invalid number of vertices.\n";
        return 1;
    }

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        key[i] = numeric_limits<int>::max();
        parent[i] = -1;
        inMST[i] = false;
    }

    key[0] = 0;
    int totalCost = 0;

    for (int count = 0; count < n; count++)
    {
        int u = -1;

        for (int i = 0; i < n; i++)
        {
            if (!inMST[i] &&
                (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        if (u == -1 || key[u] == numeric_limits<int>::max())
        {
            cout << "\nThe graph is disconnected.\n";
            return 0;
        }

        inMST[u] = true;
        totalCost += key[u];

        for (int v = 0; v < n; v++)
        {
            if (!inMST[v] && graph[u][v] != 0 &&
                graph[u][v] != 9999 &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nEdges in Minimum Spanning Tree:\n";
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i
             << " : Weight " << graph[i][parent[i]] << '\n';
    }
    cout << "\nTotal cost of Minimum Spanning Tree = "
         << totalCost << '\n';

    return 0;
}
