class Solution
{
public:
    int removeDuplicates(vector<int> &numbers)
    {
        set<int> s;
        for (int i = 0; i < numbers.size(); i++)
        {
            s.insert(numbers[i]);
        }
        numbers.clear();
        for (auto i : s)
        {
            numbers.push_back(i);
        }
        return s.size();
    }
};