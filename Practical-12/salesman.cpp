#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main()
{
    const int NO_EDGE = 99999;
    const int INF = numeric_limits<int>::max() / 2;
    int n;

    cout << "Enter number of cities: ";
    cin >> n;

    if (n <= 0 || n > 20)
    {
        cout << "Invalid number of cities.\n";
        return 1;
    }

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] >= NO_EDGE)
            {
                cost[i][j] = NO_EDGE;
            }
        }
    }

    if (!cin)
    {
        cout << "Invalid cost matrix.\n";
        return 1;
    }

    int states = 1 << n;
    vector<vector<int>> dp(states, vector<int>(n, INF));
    vector<vector<int>> parent(states, vector<int>(n, -1));

    dp[1][0] = 0;

    for (int mask = 1; mask < states; mask++)
    {
        if (!(mask & 1))
        {
            continue;
        }

        for (int city = 0; city < n; city++)
        {
            if (dp[mask][city] == INF)
            {
                continue;
            }

            for (int nextCity = 0; nextCity < n; nextCity++)
            {
                int nextBit = 1 << nextCity;
                if ((mask & nextBit) || cost[city][nextCity] == NO_EDGE)
                {
                    continue;
                }

                int nextMask = mask | nextBit;
                int nextCost = dp[mask][city] + cost[city][nextCity];

                if (nextCost < dp[nextMask][nextCity])
                {
                    dp[nextMask][nextCity] = nextCost;
                    parent[nextMask][nextCity] = city;
                }
            }
        }
    }

    if (n == 1)
    {
        cout << "\nMinimum Cost: 0";
        cout << "\nOptimal Path: 1 -> 1\n";
        return 0;
    }

    int fullMask = states - 1;
    int lastCity = -1;
    int minCost = INF;

    for (int city = 1; city < n; city++)
    {
        if (cost[city][0] != NO_EDGE &&
            dp[fullMask][city] != INF)
        {
            int totalCost = dp[fullMask][city] + cost[city][0];
            if (totalCost < minCost)
            {
                minCost = totalCost;
                lastCity = city;
            }
        }
    }

    if (lastCity == -1)
    {
        cout << "\nNo complete tour exists.\n";
        return 0;
    }

    vector<int> path;
    int mask = fullMask;
    int city = lastCity;

    while (city != -1)
    {
        path.push_back(city);
        int previousCity = parent[mask][city];
        mask ^= (1 << city);
        city = previousCity;
    }

    cout << "\nMinimum Cost: " << minCost;
    cout << "\nOptimal Path: ";
    for (int i = static_cast<int>(path.size()) - 1; i >= 0; i--)
    {
        cout << path[i] + 1 << " -> ";
    }
    cout << "1\n";

    return 0;
}
