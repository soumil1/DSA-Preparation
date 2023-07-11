class Solution
{
public:
    int majorityElement(vector<int> &numbers)
    {
        sort(numbers.begin(), numbers.end());
        return numbers[(numbers.size() - 1) / 2];
    }
};