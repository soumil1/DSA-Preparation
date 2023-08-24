// Question asked in Paytm Zoho Morgan Stanley Amazon D-E-Shaw FactSet Cisco Facebook
// Find a String which returns an Integer value 1 or 0 (GeeksForGeeks POTD - dated 25 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
public:
    int isPalindrome(string S)
    {
        // Your code goes here
        int first = 0;
        int last = S.length() - 1;

        while (first <= last)
        {
            if (S.at(first) != S.at(last))
            {
                return 0;
            }
            first++;
            last--;
        }
        return 1;
    }
};