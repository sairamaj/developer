using System;
using System.Linq;
using System.Collections.Generic;

public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution
{
    // to hold the in order index to quickly to get to the value (instead of each time finding out through loop)
    IDictionary<int, int> _inorderIndex = new Dictionary<int, int>();
    int _currentPostIndex;
    int[] _inOrder;
    int[] _preOrder;

    public TreeNode BuildTree(int[] inorder, int[] preorder)
    {
        this._inOrder = inorder;
        this._preOrder = preorder;
        // build to find out quickly about the current root in in order
        for (var i = 0; i < inorder.Length; i++)
        {
            this._inorderIndex[inorder[i]] = i;
        }

        // start with last index as this is the root.
        this._currentPostIndex = 0;
        return Build(0, inorder.Length - 1, false);
    }

    void PrintInOrder(string title, int start, int end)
    {
        System.Console.WriteLine($"________ In Order:{title} ___________");
        for (var i = start; i <= end; i++)
        {
            System.Console.Write($"{this._inOrder[i]},");
        }
        System.Console.WriteLine("\n____________________________");
    }

    private TreeNode Build(int in_left, int in_right, bool isLeft)
    {
        System.Console.WriteLine($"in_left:{in_left} in_right:{in_right}: isLeft:{isLeft}");
        if (this._currentPostIndex == this._preOrder.Length)
        {
            return null;
        }
        if (in_left > in_right)
        {
            System.Console.WriteLine($"Done isLeft:{isLeft}");
            return null; // we are done in order which is used only to find out whether it is left or right.
        }

        // get the root node from post
        var rootValue = this._preOrder[this._currentPostIndex];
        System.Console.WriteLine($"Current root:{rootValue}");
        var node = new TreeNode(rootValue);
        this._currentPostIndex++;
        // get the index in the in order.
        var inOrderIndex = this._inorderIndex[rootValue];

        PrintInOrder("Left", 0, inOrderIndex - 1);
        PrintInOrder("Right", inOrderIndex + 1, in_right);
        // now construct right nodes.
        node.left = Build(0, inOrderIndex - 1, true);
        node.right = Build(inOrderIndex + 1, in_right, false);
        return node;
    }

    void PrintPreOrder(TreeNode node)
    {
        if (node == null)
        {
            return;
        }
        if (node.left != null)
        {
            System.Console.Write($"{node.left.val},");
        }
        else
        {
            System.Console.Write($"null,");
        }

        if (node.right != null)
        {
            System.Console.Write($"{node.right.val},");
        }
        else
        {
            System.Console.Write($"null,");
        }

        PrintPreOrder(node.left);
        PrintPreOrder(node.right);
    }

    void PrintInOrder(TreeNode node)
    {
        if (node == null)
        {
            return;
        }

        PrintInOrder(node.left);
        System.Console.Write($"{node.val},");
        PrintInOrder(node.right);
    }

    void PrintPostOrder(TreeNode node)
    {
        if (node == null)
        {
            return;
        }

        PrintPostOrder(node.left);
        PrintPostOrder(node.right);
        System.Console.Write($"{node.val},");
    }

    public void Print(TreeNode node)
    {
        if (node == null)
        {
            return;
        }

        System.Console.Write($"{node.val},");
        PrintPreOrder(node);
    }

    public void Print2(TreeNode node)
    {
        if (node == null)
        {
            return;
        }

        PrintInOrder(node);
    }

    public void Print3(TreeNode node)
    {
        if (node == null)
        {
            return;
        }

        PrintPostOrder(node);
    }
}

class Test
{
    public static void Main(string[] args)
    {
        Solution sol = new Solution();
        int[] inOrder = new int[] { 9, 3, 15, 20, 7 };
        int[] preOrder = new int[] { 3, 9, 20, 15, 7 };

        TreeNode root = sol.BuildTree(inOrder, preOrder);
        sol.Print(root);
        //sol.Print2(root);
        //sol.Print3(root);
    }
}
