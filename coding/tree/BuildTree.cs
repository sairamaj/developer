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
    private TreeNode _node;

    public TreeNode Root => this._node;

    public void Build(int?[] array)
    {
        if (!array.Any())
        {
            return;
        }
        TreeNode current = new TreeNode(array[0].Value);
        this._node = current;
        Stack<TreeNode> nodes = new Stack<TreeNode>();
        bool left = true;

        foreach (var val in array.Skip(1))
        {
            if (val == null)
            {
                if (left)
                {
                    left = false;
                }
                else
                {
                    current = nodes.Pop();
                    System.Console.WriteLine($"Poping :{current.val}");
                }
            }
            else
            {
                var node = new TreeNode(val.Value);
                if (left)
                {
                    current.left = node;
                    left = false;
                }
                else
                {
                    current.right = node;
                    left = true;
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

    public IList<int> PreorderTraversalRecursive(TreeNode root)
    {
        if (root == null)
        {
            return new List<int>();
        }

        var listLeft = PreorderTraversalRecursive(root.left);
        var listRight = PreorderTraversalRecursive(root.right);

        var list = new List<int> { root.val };
        list.AddRange(listLeft);
        list.AddRange(listRight);
        return list;
    }

    public IList<int> PostTraversalIterative(TreeNode root)
    {
        var list = new List<int>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.Push(root);
        while (stack.Any())
        {
            TreeNode cur = stack.Pop();
            list.Insert(0,cur.val);

            if(cur.left != null){
                stack.Push(cur.left);
            }

            if(cur.right != null){
                stack.Push(cur.right);
            }
        }

        return list;
    }

    public IList<int> PostTraversalRecursive(TreeNode root)
    {
        if (root == null)
        {
            return new List<int>();
        }

        var listLeft = PostTraversalRecursive(root.left);
        var listRight = PostTraversalRecursive(root.right);

        var list = new List<int>();
        list.AddRange(listLeft);
        list.AddRange(listRight);
        list.Add(root.val);
        return list;
    }

    public IList<int> PreorderTraversal(TreeNode root)
    {
        var values = new List<int>();
        if (root == null)
        {
            return values;
        }

        Stack<TreeNode> items = new Stack<TreeNode>();
        items.Push(root);
        while (items.Any())
        {
            var node = items.Pop();
            values.Add(node.val);
            if (node.right != null)
            {
                items.Push(node.right);
            }
            if (node.left != null)
            {
                items.Push(node.left);
            }
        }

        return values;
    }

    public IList<int> InorderTraversal(TreeNode root)
    {
        var list = new List<int>();
        if (root == null)
        {
            return list;
        }

        list.AddRange(InorderTraversal(root.left));
        list.Add(root.val);
        list.AddRange(InorderTraversal(root.right));
        return list;
    }

    public IList<int> InorderTraversalIterative(TreeNode root)
    {
        var items = new List<int>();
        Stack<TreeNode> stack = new Stack<TreeNode>();

        TreeNode cur = root;
        while (cur != null || stack.Any())
        {
            while (cur != null)
            {
                System.Console.WriteLine($"pushing: {cur.val}");
                stack.Push(cur);
                cur = cur.left;
            }

            cur = stack.Pop();
            System.Console.WriteLine($"poped: {cur.val}");
            items.Add(cur.val);
            cur = cur.right;
        }

        return items;
    }

    public void Print()
    {
        if (this._node == null)
        {
            return;
        }

        Stack<TreeNode> items = new Stack<TreeNode>();
        items.Push(this._node);
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
        Print(this._node);
    }
}

public class Test
{
    public static void Main()
    {
        Solution sol = new Solution();
        //sol.Build(new int?[] { 1, null, 2, 3 });
        sol.Build(new int?[] { 3, 1, 2 });
        sol.Print();
        System.Console.WriteLine("____________________---");
        sol.PrintRecursive();
        System.Console.WriteLine("_____________________________");
        foreach (var item in sol.PreorderTraversal(sol.Root))
        {
            System.Console.WriteLine(item);
        }
        System.Console.WriteLine("____________Recursive_________________");
        foreach (var item in sol.PreorderTraversalRecursive(sol.Root))
        {
            System.Console.WriteLine(item);
        }

        System.Console.WriteLine("____________Recursive(alternative)_________________");
        foreach (var item in sol.PreorderTraversalRecursiveAlternative(sol.Root))
        {
            System.Console.WriteLine(item);
        }

        System.Console.WriteLine("____________In order_________________");
        foreach (var item in sol.InorderTraversal(sol.Root))
        {
            System.Console.WriteLine(item);
        }

        System.Console.WriteLine("____________In order(iterative)_________________");
        foreach (var item in sol.InorderTraversalIterative(sol.Root))
        {
            System.Console.WriteLine(item);
        }

        System.Console.WriteLine("____________Port order(recursive)_________________");
        foreach (var item in sol.PostTraversalRecursive(sol.Root))
        {
            System.Console.WriteLine(item);
        }

        System.Console.WriteLine("____________Port order(interactive)_________________");
        foreach (var item in sol.PostTraversalIterative(sol.Root))
        {
            System.Console.WriteLine(item);
        }
    }
}
