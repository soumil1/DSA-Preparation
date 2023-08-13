class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        unordered_map<int, bool> dp;
        return dfs(nums, 0, dp);
    }

    bool dfs(vector<int> &nums, int i, unordered_map<int, bool> &dp)
    {
        if (i == nums.size())
        {
            return true;
        }

        if (dp.count(i))
        {
            return dp[i];
        }

        bool res = false;
        if (i < nums.size() - 1 && nums[i] == nums[i + 1])
        {
            res = dfs(nums, i + 2, dp);
        }

        if (!res && i < nums.size() - 2)
        {
            if (nums[i] == nums[i + 1] && nums[i] == nums[i + 2] ||
                nums[i] + 1 == nums[i + 1] && nums[i + 1] == nums[i + 2] - 1)
            {
                res = dfs(nums, i + 3, dp);
            }
        }

        dp[i] = res;
        return res;
    }
};