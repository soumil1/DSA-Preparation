// Question asked in Amazon Paytm Adobe
// Convert an Array into a Zig-Zag Fashion (GeeksForGeeks - dated 06 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends
// User function Template for C++
class Solution
{
public:
    // Program for zig-zag conversion of array
    void zigZag(int arr[], int N)
    {
        // code here
        for (int i = 0; i < N - 1; i++)
        {
            if (i % 2 == 0 && arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
            else if (i % 2 == 1 && arr[i] < arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        return;
    }
};