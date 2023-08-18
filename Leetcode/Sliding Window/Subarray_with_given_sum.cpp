// Question asked in Amazon Facebook Google Visa
// Find Subarray in the given sum (GeeksForGeeks POTD - dated 19 Aug, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        int left = 0;
        int right = 0;
        vector<int> ans;
        
        if (s == 0) {
            ans.push_back(-1);
            return ans;
        }
        
        bool isFound = false;
        int sum = arr[0];
        
        while (right < n) {
            if (sum == s) {
                isFound = true;
                break;
            }
            else if (sum < s) {
                right++;
                if (right < n) sum += arr[right];
            } else {
                sum -= arr[left];
                left++; 
            }
        }
        if (isFound) {
            ans.push_back(left + 1);
            ans.push_back(right + 1);
            return ans;
        }
        ans.push_back(-1);
        return ans;
    }
};