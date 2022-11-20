/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

using System.Collections.Generic;

public class ListNode
{
    public int val;
    public ListNode next;

    public ListNode(int x)
    {
        val = x;
        next = null;
    }
}

public class Solution
{
    public ListNode DetectCycle(ListNode head)
    {
        IDictionary<ListNode, bool> visitedNodes = new Dictionary<ListNode,bool>();
        ListNode node = head;
        while (node != null)
        {
            if (visitedNodes.TryGetValue(node, out var val))
            {
                return node;
            }
            visitedNodes[node] = true;
            node = node.next;
        }

        return null;
    }
}

public class Test
{
    public static void Main() { }
}
