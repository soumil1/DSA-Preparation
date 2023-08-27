class Solution
{
public:
    bool canCross(std::vector<int> &stones)
    {
        int n = stones.size();

        // Use an unordered_map because in this case it is faster than a vector
        std::unordered_map<int, std::unordered_set<int>> dp;
        for (int stone : stones)
        {
            dp[stone] = {};
        }
        dp[0].insert(0);

        for (int i = 0; i < n; ++i)
        {
            for (int k : dp[stones[i]])
            {
                for (int step = k - 1; step <= k + 1; ++step)
                {
                    if (step > 0 && dp.find(stones[i] + step) != dp.end())
                    {
                        dp[stones[i] + step].insert(step);
                    }
                }
            }
        }
        return !dp[stones.back()].empty();
    }
};