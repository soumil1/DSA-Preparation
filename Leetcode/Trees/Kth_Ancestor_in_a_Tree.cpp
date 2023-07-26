// Question asked in
// Find the Kth Ancestor in a Tree (GeeksForGeeks POTD - dated 26 July, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver Code Ends

// User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
void helper(Node *root, stack<int> &st, int node)
{

    // Code here
    if (root == NULL)
        return;
    st.push(root->data);

    helper(root->left, st, node);
    helper(root->right, st, node);
    if (st.top() != node)
        st.pop();
}

int kthAncestor(Node *root, int k, int node)
{
    stack<int> st;
    helper(root, st, node);

    int ans = -1;
    while (!st.empty())
    {
        if (k == 0)
            ans = st.top();
        st.pop();
        k--;
    }
    return ans;
}
