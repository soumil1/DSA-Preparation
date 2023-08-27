// Question asked in
// Find func which takes integer and string as input parameters & returns Yes and No (GeeksForGeeks Contest 117 - dated 28 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    std::string flipCoins(int N, std::string s)
    {
        int count = 0;
        for (char it : s)
        {
            if (it == '0')
                count++;
        }
        if (count % 2 == 0)
            return "Yes";
        else
            return "No";
    }
};