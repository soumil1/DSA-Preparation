// Question asked in Flipkart
// Find the difference between max and min numbers of chocolate given to a student (GeeksForGeeks POTD - dated 05 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution{
public:
    long long findMinDiff(vector<long long> arr, long long n, long long m)
    {
        // code
        sort(arr.begin(), arr.end());

        long long i = 0, j = 0, mx = INT_MIN, mn = INT_MAX, res = INT_MAX;
        while (j < n)
        {
            mn = min(mn, arr[j]);
            mx = max(mx, arr[j]);
            if (j - i + 1 < m)
            {
                j++;
            }
            else if (j - i + 1 == m)
            {
                res = min((mx - mn), res);
                mn = arr[i + 1];
                i++;
                j++;
            }
        }
        return res;
    }
};