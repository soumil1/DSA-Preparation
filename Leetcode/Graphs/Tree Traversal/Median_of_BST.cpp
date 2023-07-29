// Question asked in Amazon
// Finding the Median of BST of its Node Values (GeeksForGeeks POTD - dated 29 July, 2023)

/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

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

// Driver Code Ends

// your task is to complete the Function
// Function should return median of the BST
void inOrderTraversal(Node *root, vector<int> &nodes)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left, nodes);
    nodes.push_back(root->data);
    inOrderTraversal(root->right, nodes);
}

float findMedian(Node *root)
{
    if (root == NULL)
        return 0.0;

    vector<int> nodes;
    inOrderTraversal(root, nodes);

    int n = nodes.size();
    if (n == 0)
        return 0.0;

    if (n % 2 == 0)
    {
        int mid1 = nodes[n / 2 - 1];
        int mid2 = nodes[n / 2];
        return static_cast<float>(mid1 + mid2) / 2.0;
    }
    else
    {
        return static_cast<float>(nodes[n / 2]);
    }
}