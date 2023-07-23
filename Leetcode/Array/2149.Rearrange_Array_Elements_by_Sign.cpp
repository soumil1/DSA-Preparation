class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &numbers)
    {
        vector<int> ans(numbers.size());
        int even = 0, odd = 1;
        for (int i = 0; i < numbers.size(); i++)
        {
            // iterating array
            // positive element
            if (numbers[i] > 0)
                // put on even index and increment it by 2 to maintain a series
                ans[even] = numbers[i], even += 2;
            else
                // negative element
                // put on odd index and increment it by 2
                ans[odd] = numbers[i], odd += 2;
        }
        // inplace updating done so now return
        return ans;
    }
};