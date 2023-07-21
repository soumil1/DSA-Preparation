// Question asked in Amazon Google
// Finding the Minimize Top Speed to complete the journey (GeeksForGeeks Job A Thon - dated 21 July, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
public:
    bool check(int n, vector<int> &v, long long d, long long k)
    {

        for (int i = 0; i < n; i++)
        {
            if (i + 1 < n)
            {
                long long diff = v[i + 1] - v[i];
                if (diff <= k)
                {
                    long long total = diff * (k - diff) + diff * (diff + 1) / 2;
                    d -= total;
                }
                else
                {
                    long long total = k * (k + 1) / 2;
                    d -= total;
                }
            }
            else
            {
                long long total = k * (k + 1) / 2;
                d -= total;
            }

            if (d <= 0)
                return true;
        }
        return false;
    }
    int minimizeTopSpeed(int n, vector<int> &spells, long long trackLength)
    {
        long long l = 1, h = 1e9;
        long long ans = h;
        while (l <= h)
        {
            long long mid = l + (h - l) / 2;
            if (check(n, spells, trackLength, mid))
            {
                ans = min(ans, mid);
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};