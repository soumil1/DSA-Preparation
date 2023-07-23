// Question asked in
// Finding mean of a resulting array is equal to given value in x (GeeksForGeeks Weekly Contest - dated 23 July, 2023)

// Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends
class Solution
{
public:
    bool IsMean(int n, int k, int x, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        long long int sum = (x * n);
        long long int rsum = 0;
        for (int i = 0; i < n; i++)
            rsum += arr[i];
        long long int rsumc = rsum;
        int i = 0;
        int j = n - 1;
        while (j > i)
        {
            rsum = rsumc;
            // rsum = (rsum-arr[i] - arr[j]);
            rsum = (rsum + arr[i] * (k - 1) + arr[j] * (k - 1));
            if (rsum == sum)
                return true;
            else if (rsum > sum)
                j--;
            else
                i++;
        }
        return false;
    }
};