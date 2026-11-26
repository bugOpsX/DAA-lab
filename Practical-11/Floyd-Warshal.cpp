#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int INF = 99999;
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of vertices.\n";
        return 1;
    }

    vector<vector<int>> dist(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }

    if (!cin)
    {
        cout << "Invalid adjacency matrix.\n";
        return 1;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (dist[i][k] == INF)
            {
                continue;
            }

            for (int j = 0; j < n; j++)
            {
                if (dist[k][j] == INF)
                {
                    continue;
                }

                long long candidate =
                    static_cast<long long>(dist[i][k]) + dist[k][j];

                if (candidate < dist[i][j])
                {
                    dist[i][j] = static_cast<int>(candidate);
                }
            }
        }
    }

    cout << "\nShortest Distance Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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
        cout << '\n';
    }

    return 0;
}
