#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int> &A)
{
    int N = A.size();
    if (N == 0)
        return 0;
    vector<int> dp(N, 1);
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < i; ++j)
            if (A[i] > A[j])
                dp[i] = max(dp[i], dp[j] + 1);

    return *max_element(dp.begin(), dp.end());
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    cout << longestIncreasingSubsequence(A) << '\n';
}
