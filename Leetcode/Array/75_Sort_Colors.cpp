class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int index = 0;
        for (auto x = mp.begin(); x != mp.end(); x++)
        {
            int color = x->first;
            int count = x->second;
            for (int i = 0; i < count; i++)
            {
                nums[index] = color;
                index++;
            }
        }
    }
};