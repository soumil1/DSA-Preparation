class Solution
{
public:
    void rotate(vector<int> &nums, int i)
    {
        if (i >= nums.size() // if i is greater than size of array
            i = i % nums.size()); // then take mod of i with size of array
        reverse(nums.begin(), nums.end()); // reverse the whole array
        reverse(nums.begin(), nums.begin() + i); // reverse the first i elements
        reverse(nums.begin() + i, nums.end()); // reverse the remaining elements
    }
};