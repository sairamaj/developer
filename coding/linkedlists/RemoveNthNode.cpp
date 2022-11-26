/*
    Given the head of a linked list, remove the nth node from the end of the list and return
    its head.
    Example
        Input: head = [1,2,3,4,5], n = 2
        Output: [1,2,3,5]
    Example 2:
        Input: head = [1], n = 1
        Output: []
    Example 3:
        Input: head = [1,2], n = 1
        Output: [1]
*/

/*
Strategy:
    In order to find out nth slow and fast pointer

    ex: 1,2,3,4,5 , n=2
        s:1 f:1
        s:2 f:3
        s:3 f:5
        s:4 f:null

        remove: 4
    e: 1,2,3,4,5 , n=3
        s:1 f:1
        s:2 f:4
        s:3 f:n

        remove 3:
Pseudo code
    ListNode* s = head;
    ListNode* f = head;
    ListNode* p = NULL;
    while(f != null)
    {
        int i=0;
        p = s;
        s = s->next;
        do{
            i++;
            f = f->next;
        }while(f != NULL && i=n)
    }

    // to remove s
    p->next = s->next;

*/

#include <stdio.h>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow, *fast = head;
        ListNode *prev = NULL;

        while (fast != NULL)
        {
            prev = slow;
            slow = slow->next;
            int i = 0;
            do
            {
                i++;
                fast = fast->next;
            } while (fast != NULL && i < n);
        }

        if (slow == NULL)
        {
            // nothing to remove.
        }
        if (prev == NULL)
        {
            // removing head
            head->next = slow->next;
        }
        else{
            prev->next = slow->next;
        }
    }
};

void main()
{
}