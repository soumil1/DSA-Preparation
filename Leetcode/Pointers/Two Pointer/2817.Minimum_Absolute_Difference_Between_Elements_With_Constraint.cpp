// Uses two-pointer with some concepts from sliding window

class Solution
{
public:
    int minAbsoluteDifference(vector<int> &nums, int x)
    {
        int n = nums.size();
        int ans = INT_MAX;
        set<int> s;
        int maxi = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            s.insert(nums[i]);
            maxi = max(maxi, nums[i]);
            if (i - x >= 0 && maxi >= nums[i - x])
            {
                int a = nums[i - x];
                auto b = s.lower_bound(a);
                if (b != s.end())
                    ans = min(ans, abs(*b - a));
            }
        }
        maxi = INT_MIN;
        s.clear();
        for (int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
            maxi = max(maxi, nums[i]);
            if (i + x < n && maxi >= nums[i + x])
            {
                int a = nums[i + x];
                auto b = s.lower_bound(a);
                if (b != s.end())
                    ans = min(ans, abs(*b - a));
            }
        }
        return ans;
    }
};