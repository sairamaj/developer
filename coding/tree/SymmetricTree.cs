/**
 * Given the root of a binary tree, check whether it is a mirror of itself 
 (i.e., symmetric around its center).
 */
/*
    start with root.
    send left and right of the node to compare
    if different then return false
    if same
        send left and right
ex:
    l->2 r->2
    3-l  3-r
*/
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
    public bool IsSame(TreeNode first, TreeNode second)
    {
        if (first == null && second == null)
        {
            return true;
        }
        if (first == null && second != null)
        {
            return false;
        }
        if (first != null && second == null)
        {
            return false;
        }

        if (first.val != second.val)
        {
            return false;
        }

        var ret = IsSame(first.left, second.right);
        if (!ret)
        {
            return false;
        }

        return this.IsSame(first.right, second.left);
    }

    public bool IsSymmetric(TreeNode root)
    {
        return this.IsSame(root.left, root.right);
    }

    public static void Main()
    {
        System.Console.WriteLine("test");
    }
}
