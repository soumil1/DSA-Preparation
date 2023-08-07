// Question asked in Microsoft
// Find the count of pairs of fractions whose sum equals 1 (GeeksForGeeks POTD - dated 08 August, 2023)

// Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

 // User Function template for C++

class Solution
{
public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        map<pair<int, int>, int> mp;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {

            // find out the gcd of numerator and denominator to get least value of two
            int k = __gcd(numerator[i], denominator[i]);
            // Divide by GCD to get least value of numerator and denominator possible
            int num = numerator[i] / k;
            int den = denominator[i] / k;
            // Find out whether 1 - (num/den) was encountered before or not
            int co_num = den - num;

            cnt += mp[{co_num, den}];
            mp[{num, den}] += 1;
        }
        return cnt;
    }
};
