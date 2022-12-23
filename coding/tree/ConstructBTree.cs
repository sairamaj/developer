/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a 
binary tree and postorder is the postorder traversal of the same tree, 
construct and return the binary tree.
*/

/*
Example:
    Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    Output: [3,9,20,null,null,15,7]

                        3
                      /   \
                    /      \
                    9       20
                            /  \
                           /    \
                          15     7
*/

/*
    Strategy:
        Observations:
                - root node can be obtained from post order last element: 3
                - from post order we can see the from back we can construct right side.
        Intution:
            - start from In order
            - Keep constructing tree
            - Keep change root
            - stop once root is obtained (as we already know the root from post order as each element is unique as per constraint)
            - At this point we are pretty much done on left side
            - Now start from right
        Example:
                    3
                9       20
            input: in order [9,3,20] post order: [9,20,3]
            expected: [3,9,null,null,20]

            root node: 3 (last of post order)
            start from in order:
                prevNode: 9:
                
            next: 3
                3==3 (root node)
                curNode = 3
                curNode.left = prevNode
                rootNode = curNode.
                rootleftNode = 9

            at this time we are done constructing left.
            start from post order:
                next: 20
                    root.right = 20
                    curNode = 20
                next: 9
                we have reached leftNode. so we are done.

    Leet code
        - Use in order to find out the left or right
*/

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
    int[] _postOrder;

    public TreeNode BuildTree(int[] inorder, int[] postorder)
    {
        this._inOrder = inorder;
        this._postOrder = postorder;
        // build to find out quickly about the current root in in order
        for (var i = 0; i < inorder.Length; i++)
        {
            this._inorderIndex[inorder[i]] = i;
        }

        // start with last index as this is the root.
        this._currentPostIndex = postorder.Length - 1;
        return Build(0, inorder.Length - 1, false);
    }

    private TreeNode Build(int in_left, int in_right, bool isLeft)
    {
        //System.Console.WriteLine($"in_left:{in_left} in_right:{in_right}: isLeft:{isLeft}");
        if (in_left > in_right)
        {
            return null; // we are done in order which is used only to find out whether it is left or right.
        }

        // get the root node from post
        var rootValue = this._postOrder[this._currentPostIndex];
        //System.Console.WriteLine($"Current root:{rootValue}");
        var node = new TreeNode(rootValue);
        this._currentPostIndex--;

        // get the index in the in order.
        var inOrderIndex = this._inorderIndex[rootValue];
        // now construct right nodes.
        node.right = Build(inOrderIndex + 1, in_right, false);
        node.left = Build(in_left, inOrderIndex - 1, true);
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
        int[] postOrder = new int[] { 9, 15, 7, 20, 3 };

        TreeNode root = sol.BuildTree(inOrder, postOrder);
        //sol.Print(root);
        //sol.Print2(root);
        sol.Print3(root);
    }
}
