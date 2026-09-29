#include <iostream>
using namespace std;

int main()
{
    int coins[] = {1, 2, 5};
    int n = 3;
    int amount = 11;

    int dp[100];

    // Initialize DP table
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        dp[i] = 9999;

    // Dynamic Programming
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    // Display DP table
    cout << "DP Table:\n";
    cout << "Amount : ";

    for (int i = 0; i <= amount; i++)
        cout << i << "\t";

    cout << "\nDP     : ";

    for (int i = 0; i <= amount; i++)
        cout << dp[i] << "\t";

    cout << "\n\nMinimum coins required = " << dp[amount];

    return 0;
}