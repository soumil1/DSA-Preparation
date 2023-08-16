// Question asked in Amazon Paytm Adobe Media.net Flipkart Microsoft Oyo Rooms
// Find the next smallest palindrome strictly larger than the given number (GeeksForGeeks - dated 17 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
public:
    bool AreAll9s(int num[], int n)
    {
        for (int i = 0; i < n; ++i)
            if (num[i] != 9)
                return 0;
        return 1;
    }
    bool isless(int num[], int len)
    {
        int i = (len - 1) / 2, j = len / 2;
        while (i >= 0)
        {
            if (num[i] < num[j])
                return 1;
            else if (num[i] > num[j])
                return 0;
            --i, ++j;
        }
        return 1;
    }
    vector<int> generateNextPalindrome(int num[], int n)
    {
        if (AreAll9s(num, n))
        {
            vector<int> ans(n + 1, 0);
            ans[0] = ans[n] = 1;
            return ans;
        }
        vector<int> ans(num, num + n);
        int i = (n - 1) / 2, j = n / 2, carry = isless(num, n);
        while (i >= 0)
        {
            if (carry)
            {
                if (ans[i] == 9)
                    ans[i] = 0;
                else
                    ans[i]++, carry = 0;
            }
            ans[j++] = ans[i--];
        }
        return ans;
    }
};