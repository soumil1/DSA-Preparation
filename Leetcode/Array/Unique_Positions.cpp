// Question asked in 
// Finding Unique Positions in an Array (GeeksForGeeks Job A Thon - dated 21 July, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
public:
    int uniquePositions(string moves, long long k)
    {
        unordered_map<int, int> mp;
        mp[0]++;
        int count = 0;
        for (int i = 0; i < moves.size(); i++)
        {
            if (moves[i] == 'F')
            {
                count++;
            }
            else
            {
                count--;
            }
            if (mp.find(count) == mp.end())
            {
                mp[count]++;
            }
        }
        return mp.size();
       
    }
};