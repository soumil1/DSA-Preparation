// Question asked in Amazon Google
// Finding the Non Repeating Character (GeeksForGeeks POTD - dated 20 July, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
public:
    // Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string &s)
    {
        // Your code here
        unordered_set<char> duplicateChars;
        unordered_set<char> uniqueChars;
        for (char c : s)
        {
            if (duplicateChars.find(c) == duplicateChars.end())
            {
                if (uniqueChars.find(c) != uniqueChars.end())
                {
                    uniqueChars.erase(c);
                    duplicateChars.insert(c);
                }
                else
                {
                    uniqueChars.insert(c);
                }
            }
        }
        if (uniqueChars.empty())
        {
            return '$';
        }
        for (char c : s)
        {
            if (uniqueChars.find(c) != uniqueChars.end())
            {
                return c;
            }
        }
    }
};