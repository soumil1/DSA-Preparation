class Solution
{
public:
    int singleNumber(vector<int> &numbers)
    {
        int n = 0, m = numbers.size() - 1;
        while (n < m)
        {
            if ((numbers[m] != numbers[n]))
            {
                m--;
            }
            else
            {
                numbers.erase(numbers.begin() + m);
                n++;
                m = numbers.size() - 1;
            }
        }
        return numbers[n];
    }
};