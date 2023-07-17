/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // creating the dummy node
        ListNode *dummy1 = new ListNode();
        ListNode *dummy2 = dummy1;
        // assign carry 0
        int carry = 0;

        // iterate them till either of them becomes null null and 0
        while (l1 != NULL || l2 != NULL || carry)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                // add it to sum
                sum += l1->val;
                // then move l1 to next
                l1 = l1->next;
            }

            if (l2 != NULL)
            {
                // add it to sum
                sum += l2->val;
                // them move l2 to next
                l2 = l2->next;
            }
            // add carry to sum
            sum += carry;
            // carry reinitialise to sum by 10
            carry = sum / 10;
            // create new node
            ListNode *node = new ListNode(sum % 10);
            // point the next link of dummy2 to current node created
            dummy2->next = node;
            // move dummy2 to next node
            dummy2 = dummy2->next;
        }
        return dummy1->next;
    }
};