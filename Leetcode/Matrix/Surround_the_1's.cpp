// Question asked in 
// Find no of 1's in a matrix that are surrounded by an even no (>0) of 0's (GeeksForGeeks POTD - dated 21 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int Count(vector<vector<int>> &matrix)
    {
        // Code here
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        int dr[] = {0, 1, 0, -1, 1, -1, 1, -1};
        int dc[] = {1, 0, -1, 0, 1, 1, -1, -1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 1)
                {
                    int cnt = 0;
                    for (int k = 0; k < 8; k++)
                    {
                        int ni = i + dr[k];
                        int nj = j + dc[k];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < m && matrix[ni][nj] == 0)
                            cnt++;
                    }
                    if (cnt > 0 && cnt % 2 == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};