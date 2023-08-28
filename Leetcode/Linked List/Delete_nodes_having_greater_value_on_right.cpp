// Question asked in  Amazon
// Find a func which remove nodes with values less than maximum value among their right neighbors [GeeksForGeeks POTD - dated 29 August, 2023]

/*
// Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

The structure of linked list is the following

    struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/

// Driver Code Ends

    class Solution
{
public:
    Node *reverse(Node *root)
    {
        Node *prev = NULL;
        Node *current = root;
        while (current)
        {
            Node *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    Node *compute(Node *head)
    {
        head = reverse(head);
        Node *current = head;
        int na = head->data;
        Node *prev = head;
        head = head->next;
        while (head)
        {
            if (head->data >= na)
            {
                na = head->data;
                prev = head;
                head = head->next;
            }
            else
            {
                prev->next = head->next;
                head = prev->next;
            }
        }
        head = reverse(current);
        return head;
    }
};