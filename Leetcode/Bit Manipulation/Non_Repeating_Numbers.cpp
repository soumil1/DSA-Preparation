// Question asked in Accolite Amazon Microsoft Samsung FactSet MakeMyTrip Google Qualcomm
// Find Non Repeating Numbers (GeeksForGeeks POTD - dated 14 Aug, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        vector<int> ans;
        int n = nums.size();

        // Find XOR of all numbers in the array
        int XOR = nums[0];
        for (int i = 1; i < n; i++)
        {
            XOR = XOR ^ nums[i];
        }

        // Find the rightmost set bit in XOR
        int right_bit = XOR & ~(XOR - 1);
        int x = 0, y = 0;

        // Separate numbers into x and y based on the rightmost set bit
        for (int i = 0; i < n; i++)
        {
            if (nums[i] & right_bit)
            {
                x = x ^ nums[i];
            }
            else
            {
                y = y ^ nums[i];
            }
        }

        // Push the two distinct numbers into the result vector
        ans.push_back(x);
        ans.push_back(y);

        // Sort the result vector in ascending order
        sort(ans.begin(), ans.end());

        return ans;
    }
};