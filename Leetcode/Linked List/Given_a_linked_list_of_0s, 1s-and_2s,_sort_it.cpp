// Question asked in  Amazon Microsoft MakeMyTrip
// Sorting the linked list of 0s, 1s and 2s [GeeksForGeeks POTD - dated 23 July, 2023]

// Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Linked List Node */ 



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

struct Node *start = NULL;  

// Driver Code Ends

class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        int cnt[3] = {0};

        for (Node *curr = head; curr != nullptr; curr = curr->next)
        {
            if (curr->data == 0)
                cnt[0]++;
            else if (curr->data == 1)
                cnt[1]++;
            else
                cnt[2]++;
        }

        Node *curr = head;
        int idx = 0;
        while (curr != nullptr)
        {
            if (cnt[idx] == 0)
                idx++;

            if (cnt[idx] != 0)
            {
                curr->data = idx;
                cnt[idx]--;
                curr = curr->next;
            }
        }

        return head;
    }
};
