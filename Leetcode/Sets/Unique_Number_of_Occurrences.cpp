// Question asked in Paypal Adobe Amazon Google Apple
// Find Unique Number of Occurrence (GeeksForGeeks POTD - dated 13 July, 2023)

//Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

//Driver Code Ends

class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int,int> pseudo;
        unordered_set<int> distinct;
        // Storing elements in the map and their frequencies
        for(int i=0; i<n; i++) {
            pseudo[arr[i]]++;
        }
        // Then store all the frequecies in a set
        for(const auto &x: pseudo) {
            // If the element already exists return false
            if(distinct.count(x.second)>0) {
                return false;
            }
            distinct.insert(x.second);
        }
        return true;
    }
};

// { Driver Code Starts.
// int main(){
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//         int arr[n];
//         for(int i=0; i<n; i++) {
//             cin>>arr[i];
//         Solution ob;
//         bool ans = ob.isFrequencyUnique(n, arr);
//         if(ans)
//             cout<<"1\n";
//         else
//             cout<<"0\n";
//         }
//     }
// }
// } Driver Code Ends