// Question asked in Amazon
// Find a func to print corner nodes in levels, left before right, in a tree (GeeksForGeeks POTD - dated 01 September, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

/* Function to print corner node at each level */

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

// Driver Code Ends

void printCorner(Node *root)
{

    // Your code goes here
    if (root == NULL)
        return;
    // Do level order traversal using a single queue
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // n denotes the size of the current level in the queue
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();

            // If it is leftmost corner value or rightmost corner value then print it
            if (i == 0 || i == n - 1)
                cout << temp->data << " ";

            // push the left and right children of the temp node
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}