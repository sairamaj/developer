/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
*/

/*
    Strategy:
        Intution:
            1
                1-> null  (1, null)         
            1
        2       3
                1-> null

                2-> 3
                3-> null
            1
        2       3
    4     5   6   7
              
              1-> null
              2-> 3
              3-> null

              4-> 5
              5-> 6
              6-> 7
              7-> null
            1
        2       3
    4     5   6   7
  8   9
            8->9
            9->10
            10->11
            11->12

            12->13
            13->14
            14->15
            15->16

            16-> null

    f(1, null)
      1-> null
    f(1->left, 1->right) f(2,3)
    2->3 -> null
    f(2->left, 2->right) f(4,5)
    f(3->left, 3->right)f(6,7)
        4->5 ->  6-7
    f(2->right, 3->left)  (5,6)
    3->right = null;
      4->5->6->7-> null

    f(4->left, 4->right)
*/
using System;
using System.Collections.Generic;
using System.Collections;

public class Node
{
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() { }

    public Node(int _val)
    {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next)
    {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
}

public class Solution
{
    /*
        use queue
        add root
        while(queue empty){
            // get all items queue and connect
            // for all items in queue
            //    add left and right to queue
        }
        ex:
                    1
            2            3
        4       5     6     7

        add 1:
        1->null
        add 2,3
        2->3->null
        add 4,5,6,7
        4->5->6->7->null
    */
    public Node Connect(Node root)
    {
        if (root == null)
        {
            return null;
        }
        Queue<Node> queue = new Queue<Node>();
        queue.Enqueue(root);
        while (queue.Count > 0)
        {
            List<Node> nodes = new List<Node>();
            while (queue.Count > 0)
            {
                nodes.Add(queue.Dequeue());
            }

            for (int i = 0; i < nodes.Count; i++)
            {
                if (i != nodes.Count - 1)
                {
                    nodes[i].next = nodes[i + 1];
                }
                if (nodes[i].left != null)
                {
                    queue.Enqueue(nodes[i].left);
                }
                if (nodes[i].right != null)
                {
                    queue.Enqueue(nodes[i].right);
                }
            }
            nodes[nodes.Count - 1].next = null;
        }
        return root;
    }
}

public class Test
{
    public static void Main(string[] args)
    {
        System.Console.WriteLine("Hello world!");
    }
}
