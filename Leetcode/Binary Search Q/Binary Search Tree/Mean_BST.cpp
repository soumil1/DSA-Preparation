// Question asked in
// Calculate mean of BST nodes around given key using binary search (GeeksForGeeks Contest 117 - dated 28 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int mean(Node *root, int key)
    {
        int prev = -1, next = -1;
        while (root != NULL)
        {
            if (root->data == key)
            {
                prev = root->data;
                next = root->data;
                break;
            }
            else if (root->data > key)
            {
                next = root->data;
                root = root->left;
            }
            else
            {
                prev = root->data;
                root = root->right;
            }
        }
        if (prev == -1 and next == -1)
        {
            return -1;
        }
        else
        {
            return ceil((prev + next) / 2.0);
        }
    }
};