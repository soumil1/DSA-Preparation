// Question asked in Amazon Snapdeal Makemytrip Adobe Accolite
// Finding the right view of the Binary Tree (GeeksForGeeks POTD - dated 24 July, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Tree Node

struct Node
{
    int data;
    Node *left;
    Node *right;
};
// Utility function to create a new Tree Node
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
// Driver Code Ends

/* A binary tree node has data, pointer to left child and a pointer to right child 
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
*/
// Should return  right view of tree
class Solution
{
public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        // Your Code here
        queue<Node *> q;
        vector<int> ans;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                Node *temp = q.front();
                q.pop();
                if (i == 0)
                    ans.push_back(temp->data);
                if (temp->right)
                    q.push(temp->right);
                if (temp->left)
                    q.push(temp->left);
            }
        }
        return ans;
    }
};
