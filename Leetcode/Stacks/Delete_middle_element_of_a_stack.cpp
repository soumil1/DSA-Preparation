// Question asked in Microsoft
// How to Delete middle element of a stack (GeeksForGeeks POTD - dated 15 July, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int> &s, int si)
    {
        // code here..
        int i = 0;
        int n = si / 2;
        stack<int> s1;
        while (i < n)
        {
            int a = s.top();
            s.pop();
            s1.push(a);
            i++;
        }
        s.pop();

        while (!s1.empty())
        {
            int a = s1.top();
            s1.pop();
            s.push(a);
        }
    }
};