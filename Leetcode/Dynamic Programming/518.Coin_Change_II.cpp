class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // created a 2D array to store count of combinations
        std::vector<std::vector<int>> dp(amount + 1, 
        std::vector<int>(coins.size() + 1, 0));

        // base case: 1 way to make amount 0 using any coins
        for (int i = 0; i <= coins.size(); ++i) {
            dp[0][i] = 1;
        }

        // loop through amounts, coins and update DP table
        for (int a = 1; a <= amount; ++a) {
            for (int i = coins.size() - 1; i >= 0; --i) {
                dp[a][i] = dp[a][i + 1];
                if (a - coins[i] >= 0) {
                    dp[a][i] += dp[a - coins[i]][i];
                }
            }
        }
        
        // return count of combinations
        return dp[amount][0];
    }
};