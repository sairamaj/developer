/**
    Status: Not done.
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

    public bool IsSymmetric(TreeNode root)
    {
        if (root == null)
        {
            return true;
        }
    }

    public static void Main()
    {
        System.Console.WriteLine("test");
    }
}
