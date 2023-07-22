// Question asked in  Amazon Intuit
// How to remove duplicates from an unsorted linked list [GeeksForGeeks POTD - dated 22 July, 2023]

/*
The structure of linked list is following 

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }

*/

class Solution
{
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        // your code goes here
        unordered_map<int, int> mp;
        Node *prev = NULL;
        Node *curr = head;

        while (curr)
        {
            if (mp[curr->data] == 0)
            {
                mp[curr->data] = 1;
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev->next = curr->next;
                curr = curr->next;
            }
        }
        return head;
    }
};
