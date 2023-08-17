// Question asked in Adobe PayU
// Find and return an array of leader in order of their appearance (GeeksForGeeks - dated 18 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int a[], int n)
    {
        // Code here
        vector<int> ans;
        int max_element = a[n - 1];
        ans.push_back(a[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] >= max_element)
            {

                ans.push_back(a[i]);

                max_element = a[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};