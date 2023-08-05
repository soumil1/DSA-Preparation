// Question asked in Accolite Amazon OYO Rooms Samsung Citrix MAQ Software Cisco
// Find String Permutation of a string (GeeksForGeeks POTD - dated 06 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution{
    public:
        // Complete this function
        vector<string> ans;
        void help(int ind, string s, string &temp)
        {
            if (ind == s.size())
            {
                ans.push_back(temp);
                return;
            }
            for (int i = ind; i < s.size(); i++)
            {
                temp += s[i];
                swap(s[i], s[ind]);
                help(ind + 1, s, temp);

                temp.pop_back();
                swap(s[i], s[ind]);
            }
        }
        vector<string> permutation(string s)
        {
            // Your code here
            string temp = "";
            help(0, s, temp);
            sort(ans.begin(), ans.end());
            return ans;
        }
};
