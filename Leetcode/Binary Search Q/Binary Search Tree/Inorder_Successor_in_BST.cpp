// Question asked in Amazon Microsoft Morgan Stanley
// Find Inorder Successor of the given node in the BST (GeeksForGeeks POTD - dated 30 July, 2023)

// Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node *parent;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Driver Code Ends

class Solution
{
public:
    struct Node *findMin(Node *node)
    {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    struct Node *inOrderSuccessor(struct Node *root, struct Node *x)
    {
        if (x->right != NULL)
            return findMin(x->right);

        struct Node *successor = NULL;
        while (root != NULL)
        {
            if (x->data < root->data)
            {
                successor = root;
                root = root->left;
            }
            else if (x->data > root->data)
            {
                root = root->right;
            }
            else
            {
                break;
            }
        }
        return successor;
    }
};
