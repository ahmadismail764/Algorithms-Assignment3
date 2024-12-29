#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve the knapsack problem using dynamic programming
int knapsack(int max_weight, const vector<pair<int, int>> &bags) {
    // Initialize a DP array where dp[w] represents the maximum value for weight w
    vector<int> dp(max_weight + 1, 0);

    // Process each bag
    for (const auto &bag : bags) {
        int weight = bag.first;
        int value = bag.second;
        // Traverse the DP array in reverse to prevent overwriting values we need
        for (int w = max_weight; w >= weight; --w) {
            dp[w] = max(dp[w], dp[w - weight] + value);
        }
    }

    // The maximum value the robber can get is stored in dp[max_weight]
    return dp[max_weight];
}

int main() {
    int N; // Number of test cases
    cin >> N;

    vector<string> results;

    for (int i = 0; i < N; ++i) {
        int K, M; // Max weight and number of bags
        cin >> K >> M;

        vector<pair<int, int>> bags(M);
        for (int j = 0; j < M; ++j) {
            int A, B; // Weight and value of the bag
            cin >> A >> B;
            bags[j] = {A, B};
        }

        // Solve the problem for this test case
        int max_value = knapsack(K, bags);

        // Store the result
        results.push_back("Hey stupid robber, you can get " + to_string(max_value) + ".");
    }

    // Print all results
    for (const string &result : results) {
        cout << result << endl;
    }

    return 0;
}
