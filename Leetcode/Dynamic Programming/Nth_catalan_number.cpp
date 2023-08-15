// Question asked in Amazon
// Finde Nth Catalan Number (GeeksForGeeks POTD - dated 16 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends 

class Solution{
public:
    // Function to find the nth catalan number.
    int findCatalan(int n)
    {
        // code here
        long long int catalan[n + 1];

        catalan[0] = catalan[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            catalan[i] = 0;
            for (int j = 0; j < i; j++)
            {
                catalan[i] += catalan[j] * catalan[i - j - 1];
                catalan[i] %= 1000000007;
            }
        }
        return catalan[n];
    }
};

