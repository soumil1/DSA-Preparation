// Question asked in
// Find minimum number of operations required to make the arrays empty (GeeksForGeeks Contest 116 - dated 21 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int min_operations(int n, vector<int> &arr, vector<int> &brr)
    {
        // code here
        int count = 0;
        int j = 0;
        queue<int> q;
        for (int i = 0; i < arr.size(); i++)
        {
            q.push(arr[i]);
        }
        while (!q.empty())
        {
            count++;
            if (q.front() == brr[j])
            {
                j++;
                q.pop();
            }
            else
            {
                int t = q.front();
                q.pop();
                q.push(t);
            }
        }
        return count;
    }
};