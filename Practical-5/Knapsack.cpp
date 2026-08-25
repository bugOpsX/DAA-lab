#include <iostream>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[100], value[100];

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // DP table
    int dp[101][101] = {0};

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            // If current item's weight is less than or equal to capacity
            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nMaximum value = " << dp[n][capacity] << endl;

    return 0;
}
