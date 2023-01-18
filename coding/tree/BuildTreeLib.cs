using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode (int val = 0, TreeNode left = null, TreeNode right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class TreeBuilder {
    public TreeNode Build (int?[] array) {
        if (!array.Any ()) {
            return null;
        }

        // create root node
        var root = new TreeNode (array[0].Value);
        var queue = new Queue<TreeNode> ();
        queue.Enqueue (root);

        // { 5, 8, 6, null, 9, 3, null, 4, 2 }
        for (int i = 1; i < array.Length - 1;) {
            var node = queue.Dequeue ();
            if (array[i] != null) {
                var leftNode = new TreeNode (array[i].Value);
                node.left = leftNode;
                queue.Enqueue (leftNode);
            }
            i++;
            if (i < array.Length && array[i] != null) {
                var rightNode = new TreeNode (array[i].Value);
                node.right = rightNode;
                queue.Enqueue (rightNode);
            }
            i++;
        }

        return root;
    }

    public void PrintBfs (TreeNode node) {
        if (node == null) {
            return;
        }
        var list = new List<int?> ();
        list.Add (node.val);
        var queue = new Queue<TreeNode> ();
        queue.Enqueue (node);
        while (queue.Count > 0) {
            node = queue.Dequeue ();
            if (node.left != null) {
                list.Add (node.left.val);
                queue.Enqueue (node.left);
            } else {
                list.Add (null);
            }
            if (node.right != null) {
                list.Add (node.right.val);
                queue.Enqueue (node.right);
            } else {
                list.Add (null);
            }
        }

        // remove all end nulls.
        var filteredList = new List<int?> ();
        int currentNulls = 0;
        foreach (var l in list) {
            if (l != null) {
                for (int i = 0; i < currentNulls; i++) {
                    filteredList.Add (null);
                }
                filteredList.Add (l);
                currentNulls = 0;
            } else {
                currentNulls++;
            }
        }
        foreach (var l in filteredList) {
            if (l == null) {
                System.Console.Write ($"null,");
            } else {
                System.Console.Write ($"{l},");
            }
        }
    }

    public class Test {
        public static void Main () {
            int?[] array = { 5, 8, 6, null, 9, 3, null, 4, 2 };
            foreach (var x in array) {
                if (x == null) {
                    System.Console.Write ($"null,");
                } else {
                    System.Console.Write ($"{x},");
                }
            }
            System.Console.WriteLine();
            var builder = new TreeBuilder ();
            var node = builder.Build (array);
            builder.PrintBfs (node);
        }
    }
}