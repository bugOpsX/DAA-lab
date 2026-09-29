#include <iostream>
using namespace std;

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

// Add an edge
void addEdge(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;   // Undirected graph
}

// DFS
void DFS(int vertex)
{
    cout << vertex << " ";
    visited[vertex] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

// BFS
void BFS(int start)
{
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        int vertex = queue[front++];
        cout << vertex << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int edges, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        addEdge(u, v);
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    // DFS
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "\nDFS: ";
    DFS(start);

    // BFS
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "\nBFS: ";
    BFS(start);

    return 0;
}