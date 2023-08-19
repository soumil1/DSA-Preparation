// Question asked in Amazon Zoho MakeMyTrip
// Find Number of occurences of no. X an an Array (GeeksForGeeks POTD - dated 20 August, 2023)

// Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x)
    {
        // Finding the first occurrence of x using binary search
        int first = binarySearch(arr, 0, n - 1, x, true);

        // Finding the last occurrence of x using binary search
        int last = binarySearch(arr, 0, n - 1, x, false);

        if (first == -1 || last == -1)
        {
            return 0;
        }
        return last - first + 1;
    }

private:
    int binarySearch(int arr[], int left, int right, int target, bool findFirst)
    {
        int result = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target)
            {
                result = mid;
                if (findFirst)
                {
                    right = mid - 1; // Search for the first occurrence on the left side
                }
                else
                {
                    left = mid + 1; // Search for the last occurrence on the right side
                }
            }
            else if (arr[mid] < target)
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
