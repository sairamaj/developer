#include <stdio.h>
/*
    Strategy
        [4,2,1,3]
        // node, nextnode
        // 4 ,2
        // move 2
            // [2,4,1,3] head = nodeToMove, nodeToMove->next = head
        // curNode->next = 3 (take backup of next as this will change)
        // curNode = 4 nextNode,1
        // node to move 1
        // move 1  ( [2,4,1,3])
            // [1,2,4,3]  newhad = 1 1->next = 2
        // 4->next = 3
        // curnode 3, next=3
        // move 3
            // [1,2,4,3]
            // node=4, prev:2
            // 2->next = 3
            // 3->next = 4
            // [1,2,3,4]
*/

/*
    Status:
        Works but to make it simple use pseudo code as per leet code sample.
*/
// Use Pseudo node to make the logic simple.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *move(struct ListNode *nodeToMove, struct ListNode *head)
{
    printf("nodeToMove:%d\n", nodeToMove->val);
    // node to move: 2
    // [2,4,1,3]
    // node to move:1
    // [1,2,4,3]
    struct ListNode *node = head;
    struct ListNode *prev = NULL;
    struct ListNode *newHead = head;
    while (node != NULL)
    {
        // 4->2->1->3
        if (node->val > nodeToMove->val)
        {
            if (prev == NULL)
            {
                printf("moving head.");
                newHead = nodeToMove; // newhead = 2 , 1
                if(head->next == nodeToMove)
                {
                    head->next = nodeToMove->next;
                }
                nodeToMove->next = head; 
                // [4,2,1,3]
                // node to move: 2: [2,4,1,3]
                // node to move: 1: [1,2,]
            }
            else
            {
                prev->next = nodeToMove; // prev: 1
                nodeToMove->next = node; // 2->3
            }

            break;
        }

        prev = node;
        node = node->next;
    }

    printf("returning newHead:%d\n", newHead->val);
    return newHead;
}
struct ListNode *insertionSortList(struct ListNode *head)
{
    // ex:[4,2,1,3]
    struct ListNode *node = head;
    while (node != NULL && node->next != NULL)
    {
        printf("node:%d node->next:%d\n", node->val, node->next->val);
        if (node->val > node->next->val)
        {
            // node:4 node->next = 2;
            struct ListNode* nodeToMove = node->next;
            struct ListNode* temp = nodeToMove->next;
            head = move(nodeToMove, head); // 2,
            node->next = temp;                  
        }
        else
        {
            node = node->next; // 3->next will be null
        }
    }

    printf("returning from insertion.:%d\n", head->val);
    return head;
}
void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d-", array[i]);
    }

    printf("\n");
}

void main()
{
    // int array[] = {3, 5, 1, 6, 1};
}
