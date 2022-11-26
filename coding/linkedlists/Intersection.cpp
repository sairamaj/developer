/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
For example, the following two linked lists begin to intersect at node c1:
*/
/*
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation:
The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5].
There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node
in B. - Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.
*/

/*
Strategy:
    Thought: Go to the end of each list and start working backwards:
    Notes: Does not work as this is single linked list and cannot walk backwards.

    Thought: Reverse the linked list and then work backwards.
    How do you reverse?
 */
#include <stdio.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *reveseInternal(ListNode *node)
    {
        // 1->2->3->4->5
        ListNode *current = node;
        if (current == NULL)
        {
            return NULL;
        }

        // A->B->C->D->E->NULL
        // c:A n:B
        // B->A
        // c:B n:C
        // C->B
        //
        // E
        ListNode *next = current->next;
        current->next = NULL;
        while (next != NULL)
        {
            ListNode *temp = next->next;
            next->next = current;
            current = next;
            next = temp;
        }

        return current;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // go the last
        ListNode *nodeA = reveseInternal(headA);
        ListNode *nodeB = reveseInternal(headB);

        ListNode* nodeAHead = nodeA;
        ListNode* nodeBHead = nodeB;

        ListNode *intersection = NULL;
        while (nodeA != NULL && (nodeA == nodeB))
        {
            intersection = nodeA;
            nodeA = nodeA->next;
            nodeB = nodeA->next;
        }

        reveseInternal(nodeAHead);
        reveseInternal(nodeBHead);
        return intersection;
    }
};