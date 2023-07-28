// Question asked in Amazon Microsoft Samsung Flipkart Accolite MAQ Software Synopsys
// Find Lowest Common Ancestor in a BST (GeeksForGeeks POTD - dated 28 July, 2023)

// Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};
// Function to build tree

// Driver Code Ends

// Function to find Lowest Common Ancestor of two nodes n1 and n2.

class Solution
{
public:
    Node *LCA(Node *root, int n1, int n2)
    {
        // code here
        if (!root)
        {
            return NULL;
        }
        if (n1 < root->data && n2 > root->data || n1 > root->data && n2 < root->data)
        {
            return root;
        }
        else if (n1 < root->data && n2 < root->data)
        {
            return LCA(root->left, n1, n2);
        }
        else if (n1 > root->data && n2 > root->data)
        {
            return LCA(root->right, n1, n2);
        }
        return root;
    }
};