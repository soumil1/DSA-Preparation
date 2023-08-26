// Question asked in 
// Find the reverse of String s (GeeksForGeeks POTD - dated 27 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
public:
    std::string reverseWord(std::string str)
    {
        int left = 0;
        int right = str.size() - 1;

        while (left < right)
        {
            std::swap(str[left], str[right]);
            left++;
            right--;
        }

        return str;
    }
};
