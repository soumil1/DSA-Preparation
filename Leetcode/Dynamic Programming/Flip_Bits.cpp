// Question asked in Amazon 
// Finde max no of 1's in an array after atmost one flip operation (GeeksForGeeks POTD - dated 15 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
public:
    int maxOnes(int a[], int n)
    {
        int ans = 0, zero = 0, one = 0;
        for (int i = 0; i < n; i++)
        {
            if (!a[i])
            {
                zero++;
            }
            else
            {
                zero--;
                one++;
            }
            ans = max(zero, ans);
            if (zero < 0)
            {
                zero = 0;
            }
        }
        return ans + one;
    }
};
