// Question asked in  Samsung
// Find a func which delete the xth node from a singly LinkedList, and then return the modified head [GeeksForGeeks POTD - dated 30 August, 2023]

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

// Driver Code Ends

/*You are required to complete below method*/
Node *deleteNode(Node *head, int x)
{
    if (x == 1)
        return head->next;
    Node *curr = head;
    int pos = 1;

    // Traverse the list to find the node before the one to be deleted
    while (++pos != x)
        curr = curr->next;

    // Update pointers to delete the node at position x
    curr->next = (curr->next ? curr->next->next : NULL);
    return head;
}