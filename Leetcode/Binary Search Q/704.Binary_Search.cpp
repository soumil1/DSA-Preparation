class Solution
{
public:
    int search(vector<int> &numbers, int target)
    {
        int start = 0;
        int end = numbers.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (numbers[mid] == target)
            {
                return mid;
            }
            else if (numbers[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
};