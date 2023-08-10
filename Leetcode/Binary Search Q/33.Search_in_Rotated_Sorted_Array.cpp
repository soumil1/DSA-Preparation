class Solution
{
public:
    int search(vector<int> &arr, int k)
    {
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == k)
                return mid;

            // left sorted
            if (arr[low] <= arr[mid])
            {
                if (k >= arr[low] && k <= arr[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            // right sorted
            else
            {
                if (k >= arr[mid] && k <= arr[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};