#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int u;
    int v;
    int weight;
};

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    explicit DisjointSet(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV)
        {
            return;
        }

        if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else if (rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }

    bool connected(int u, int v)
    {
        return find(u) == find(v);
    }
};

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    if (n <= 0 || e < 0)
    {
        cout << "Invalid number of vertices or edges.\n";
        return 1;
    }

    vector<Edge> edges;
    edges.reserve(e);

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < e; i++)
    {
        Edge edge;
        cin >> edge.u >> edge.v >> edge.weight;

        if (edge.u < 0 || edge.u >= n ||
            edge.v < 0 || edge.v >= n)
        {
            cout << "Invalid edge encountered.\n";
            return 1;
        }

        edges.push_back(edge);
    }

    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b)
         {
             return a.weight < b.weight;
         });

    DisjointSet disjointSet(n);
    vector<Edge> mst;
    int totalCost = 0;

    for (const Edge& edge : edges)
    {
        if (!disjointSet.connected(edge.u, edge.v))
        {
            disjointSet.unite(edge.u, edge.v);
            mst.push_back(edge);
            totalCost += edge.weight;

            if (mst.size() == static_cast<size_t>(n - 1))
            {
                break;
            }
        }
    }

    if (n > 1 && mst.size() != static_cast<size_t>(n - 1))
    {
        cout << "\nThe graph is disconnected.\n";
        return 0;
    }

    cout << "\nEdges in Minimum Spanning Tree:\n";
    for (const Edge& edge : mst)
    {
        cout << edge.u << " - " << edge.v
             << " Weight: " << edge.weight << '\n';
    }
    cout << "\nTotal cost of Minimum Spanning Tree = "
         << totalCost << '\n';

    return 0;
}
