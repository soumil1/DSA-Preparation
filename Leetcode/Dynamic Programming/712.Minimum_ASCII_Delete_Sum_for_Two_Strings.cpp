class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();

        // Initialize a 2D vector 'dp' to store the minimum sum of ASCII values required.
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Fill the first column of 'dp' table, representing deleting characters from s1 to make it an empty string.
        for (int i = 1; i <= n1; i++)
        {
            dp[i][0] = dp[i - 1][0] + int(s1[i - 1]); // minimum sum is sum of ASCII value of characters in s1

        // Fill the first row of 'dp' table, representing deleting characters from s2 to make it an empty string.
        for (int j = 1; j <= n2; j++)
        {
            dp[0][j] = dp[0][j - 1] + int(s2[j - 1]); // The minimum sum is the sum of ASCII values of characters in s2.
        }

        // Fill the rest of the 'dp' table using dynamic programming approach.
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    // If the characters are the same at the current position, no need to delete, so take the value from the diagonal.
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // If the characters are different, find the minimum sum of ASCII values from either deleting character from s1 or s2.
                    dp[i][j] = min(dp[i - 1][j] + int(s1[i - 1]), dp[i][j - 1] + int(s2[j - 1]));
                }
            }
        }

        // The final value in the 'dp' table represents the minimum sum of ASCII values required to make both strings equal.
        return dp[n1][n2];
    }
};