#include <vector>

class Solution
{
public:
    int numMusicPlaylists(int n, int goal, int k)
    {
        int mod = 1e9 + 7;

        // Create a 2D DP table to store the results
        std::vector<std::vector<long long>> dp(goal + 1, std::vector<long long>(n + 1, 0));
        dp[0][0] = 1;

        // Fill in the DP table
        for (int i = 1; i <= goal; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // Choose a new song
                dp[i][j] = (n - j + 1) * dp[i - 1][j - 1] % mod;

                // Choose an old song if the number of old songs is greater than k
                if (j > k)
                {
                    dp[i][j] = (dp[i][j] + (j - k) * dp[i - 1][j]) % mod;
                }
            }
        }

        return dp[goal][n];
    }
};
