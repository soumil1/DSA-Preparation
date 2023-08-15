// Question asked in Yahoo
// Find the sum of series in an array (GeeksForGeeks Solution)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
public:
    // function to return sum of  1, 2, ... n
    long long seriesSum(int n)
    {
        // code here
        // using formula for sum of arithmetic logic and prevents int overflow by casting n and n+1 to long
        long sum = ((long)n * ((long)n + 1)) / 2;
        return (sum);
    }
};