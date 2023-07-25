// Question asked in Flipkart Morgan Stanley Accolite  Amazon Microsoft Hike Housing.com MakeMyTrip Ola Cabs Payu Teradata Walmart Adobe
// Finding Level order traversal in spiral form(POTD - dated 25 July, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Tree Node    

struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node

Node* newNode(int val) 
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

vector<int> findSpiral(Node *root);

// Driver Code Ends

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    // Your code here

    // Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;

    // creates a queue and pushes root node into the queue
    queue<Node *> q;
    q.push(root);
    int a = 0;

    // created a while loop, it terminates when queue is empty
    while (!q.empty())
    {

        int size = q.size();
        // creates a vector to store nodes
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);

            level.push_back(node->data);
        }

        // check if the flag is 1
        if (a == 1)
        {
            for (int i = 0; i < level.size(); i++)
            {
                ans.push_back(level[i]);
                a = 0;
            }
        }
        else
        {
            for (int i = level.size() - 1; i >= 0; i--)
            {
                ans.push_back(level[i]);
                // flips the flag 'a'
                a = 1;
            }
        }
    }
    return ans;
}
