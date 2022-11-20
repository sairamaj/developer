/**
 * Definition for singly-linked list.
 */

/*
    Strategy:
        Floyd's Tortoise and Hare
        Find intersection through slow and fast
        Then move pointer from begingin and intersection and when they meet it is entrance.
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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *intersection = NULL;

        while (fast != NULL) 
        {
            slow = slow->next;
            if (fast->next == NULL)
            {
                return NULL;
            }

            fast = fast->next->next;
            if(slow == fast){
                intersection = slow;
                break;
            }
        }

        // find the interance
        slow = head;

        if(intersection == NULL){
            return NULL;            
        }
        while( slow != intersection)
        {
            slow = slow->next;
            intersection = intersection->next;
        }

        return intersection;
    }
};