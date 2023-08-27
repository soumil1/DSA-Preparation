// Question asked in Microsoft OYO Rooms Oracle Visa Adobe Myntra
// Find a function that removes the duplicate from LinkedList & return the head of LinkedList [GeeksForGeeks POTD - dated 28 August, 2023]


// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Driver Code Ends

Node *removeDuplicates(Node *root)
{
    // your code goes here
    Node *head = root;
    if (!head)
        return NULL;
    while (head->next != NULL)
    {
        if (head->data == head->next->data)
        {
            head->next = head->next->next;
        }
        else
            head = head->next;
    }
    return root;
}