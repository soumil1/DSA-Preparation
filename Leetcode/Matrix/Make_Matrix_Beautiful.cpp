// Question asked in 
// Find minimum no of operations that are required to make the matrix beautiful (GeeksForGeeks POTD - dated 22 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find minimum number of operations that are required
    // to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int>> matrix, int n)
    {
        // code here
        int maxSum = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int sum1 = 0;
            int sum2 = 0;
            for (int j = 0; j < n; j++)
            {
                sum1 += matrix[i][j];
                sum2 += matrix[j][i];
            }
            maxSum = max(maxSum, sum1);
            maxSum = max(maxSum, sum2);
            sum += sum1;
        }
        return (maxSum * n - sum);
    }
};
