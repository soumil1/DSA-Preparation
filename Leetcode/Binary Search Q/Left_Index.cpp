// Question asked in
// Find leftmost index of X in the array arr[] (GeeksForGeeks DSA to Development - dated 18 Aug, 2023)

class Solution
{
public:
    int leftIndex(int N, int arr[], int X)
    {
        int left = 0, right = N - 1, result = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] == X)
            {
                result = mid;
                right = mid - 1; // Move left to find the leftmost occurrence
            }
            else if (arr[mid] < X)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }
};