/*
    Purpose
        Build tree from given string array
    Example
        [1,null, 2, 3, null, 5]
        Output:
                1
                      2
                   3    5
*/
/*
    Strategy
        final structure in mem is
                   root
        l:(null)           r(2)
                        l(3)     r(null)
                 (null)         (null)

    1: allocate root , push it to stack
    (null)
    2 : create root and add it to right of previous root
        push root (2)
    3:  create root: add left to previous root (3->2). push
    4:  (null), pop root (2)
    5:  create root and add it to right (2->5)
        push this root
    
    Pseudo
        [1,null,2,3,null,5]
        stack nodes;
        Root : 1
        nodes.push(1)
        (null)
        pop root(1)
        2 : root->right
        push(2)
        3 : root->left
        push 3
        (null)
        popd
*/

/*
    Path Sum:
        - start with root:
        - reduce the value from target sum
        - if 0 and there are no children then true
        - if 0 but children then false
        - if < 0 return false;
        - if > 0 check with left sub
        - if false
        - check with right sub
    ex:
        root: 5: target: 22
        22-5 = 17
        > 0
        go left:
            17-4 = 13
        > 0 
        go left
            13-11 = 2
        > 0
        go left
          2-7 = -5
        < 0
        go right
        2-2 = 0
        if no children
            return true;
*/
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

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
    private TreeNode _root;

    public TreeNode Root => this._root;

    public void Build(int?[] array)
    {
        if (!array.Any())
        {
            return;
        }

        // 3,9,20,null,null,15,7
        // cur: 3  -> 9,20
        // cur: 9   -> queue
        //      null -> done left
        //      null -> done right
        // cur:20
        //      15  -> left
        //       7  -> right
        // cur:15

        // cur:3 (queue)
        // get fromqueue
        // get next: 2-> add (l). add(r)
        // queue(l)
        // queue(r)
        // get from queue
        // get next 2

        // 3-> 3(from q)-> get(9,20) -> add 3->9l, 3->20r
        // 9to q , 20 to queue
        // next loop
        //  get from queu :9
        // get next 2
        //  null-> skip left , null -> skip right
        //  get from queue
        // 20
        // get 15, 17
        // add 20->15l , 20->17r

        Queue<TreeNode> queue = new Queue<TreeNode>();
        var root = new TreeNode(array[0].Value);
        this._root = root;
        queue.Enqueue(root);
        for (int i = 1; i < array.Length; i += 2)
        {
            var node = queue.Dequeue();
            var left = array[i];
            if (left != null)
            {
                System.Console.WriteLine($"Adding left:{left} to {node.val}");
                node.left = new TreeNode(left.Value);
                queue.Enqueue(node.left);
            }
            if ((i + 1) < array.Length)
            {
                var right = array[i + 1];
                if (right != null)
                {
                    System.Console.WriteLine($"Adding right:{right} to {node.val}");
                    node.right = new TreeNode(right.Value);
                    queue.Enqueue(node.right);
                }
            }
        }
    }

    class Collector
    {
        public IList<int> list = new List<int>();

        public void Collect(TreeNode node)
        {
            if (node == null)
            {
                return;
            }

            list.Add(node.val);
            Collect(node.left);
            Collect(node.right);
        }
    }

    public IList<int> PreorderTraversalRecursiveAlternative(TreeNode root)
    {
        Collector collector = new Collector();
        collector.Collect(root);
        return collector.list;
    }

    public void Print()
    {
        if (this._root == null)
        {
            return;
        }

        Stack<TreeNode> items = new Stack<TreeNode>();
        items.Push(this._root);
        while (items.Any())
        {
            var node = items.Pop();
            System.Console.WriteLine(node.val);
            if (node.right != null)
            {
                items.Push(node.right);
            }
            if (node.left != null)
            {
                items.Push(node.left);
            }
        }
    }

    void Print(TreeNode node)
    {
        if (node == null)
        {
            return;
        }

        System.Console.WriteLine(node.val);
        Print(node.left);
        Print(node.right);
    }

    public void PrintRecursive()
    {
        Print(this._root);
    }

    public int GetDepth(TreeNode node, int current)
    {
        //System.Console.WriteLine($"node:{node}: current:{current}");
        if (node == null)
        {
            //System.Console.WriteLine($"returning current:{current}");
            return current;
        }

        //System.Console.WriteLine($"node:{node.val} current:{current}");
        var depthAtLeft = GetDepth(node.left, current + 1);
        var depthAtRight = GetDepth(node.right, current + 1);

        //System.Console.WriteLine($"depthAtLeft:{depthAtLeft} depthAtRight:{depthAtRight}");
        return depthAtLeft > depthAtRight ? (depthAtLeft) : (depthAtRight);
    }

    public int MaxDepth(TreeNode root)
    {
        return GetDepth(root, 0);
    }

    private bool IsLeaf(TreeNode root)
    {
        return root.left == null && root.right == null;
    }

    public bool HasPathSum(TreeNode root, int targetSum)
    {
        if (root == null)
        {
            return false;
        }
        int remain = targetSum - root.val;
        System.Console.WriteLine($"remain:{remain}");
        if (remain == 0 && this.IsLeaf(root))
        {
            return true; //found
        }

        // check with left
        var ret = HasPathSum(root.left, remain);
        if (ret)
        {
            return true;
        }
        return HasPathSum(root.right, remain);
    }
}

public class Test
{
    public static void Main()
    {
        Solution sol = new Solution();
        //sol.Build(new int?[] { 1, 2, 3 });
        //sol.Build(new int?[] { 3, 9, 20, null, null, 15, 7 });
        //sol.Build(new int?[] { 5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1 });
        sol.Build(new int?[] { 1,2,3 });

        sol.Print();
        //System.Console.WriteLine("Max Depth:{0}", sol.MaxDepth(sol.Root));
        System.Console.WriteLine("Max Depth:{0}", sol.HasPathSum(sol.Root, 5));
    }
}
