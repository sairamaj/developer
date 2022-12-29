/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor 
is defined between two nodes p and q as the lowest node in T that has both p and q 
as descendants (where we allow a node to be a descendant of itself).”
*/

/*
    Build Strategy: 
        Thi is BFS travarsal nodes.
            3,5,1,6,2,0,8,null,null,7,4
        Create queue.
        Push 3 first and construct root node.
        Next push 2
            5,1
            pop node and attach left and right
                r.l = 5, r.r = 1
            push 5n , 1n
        Next push 4
            6,2,0,8
            pop 5n
                5n.l =6 , 5n.r=2
                1n.l =0   1n.r=8
            push 6n,2n,0n,8n
        Next push 8
            null,null,7,4
            pop
                (null,null)6n
                    6n.l=null  6n.r=null
                (7,4)
                    2n.l=7 2n.r=4

    :strategy-2
        3,5,1,6,2,0,8,null,null,7,4
        create root node with 3 and push it.
        take next 2 and attach left and right
            3.l = 5
            3.r = 1;
        push 5, push 1
            5.l = 6;
            5.r = 2
            push:6 push:2
        pop 1
            5.l = 
    strategy for LCA
        : walk through BFS
        : build for each node list of parents
        : when done find out which is last common parent between 2 nodes.

        : How to build list of parents.
        
        Logic:
            start with root;
            add it to map
                map[root] = new List<Node> { root}
            use pre order
                GetParent(list.left,currentParentlist)
                    f(3, [])
                {3} = [3]            
            f(5,[3])             f(1,[3])
        {5} = [3,5]             {1} = {1,3}
          f(6,[3,5])
        {6} = [3,5,6]



        
*/
using System;
using System.Linq;
using System.Collections.Generic;

public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode(int x)
    {
        val = x;
    }
}

public class LcaCalculator
{
    private IDictionary<int, List<TreeNode>> _nodeParentsMap = new Dictionary<
        int,
        List<TreeNode>
    >();

    public void WalkForParents(TreeNode root)
    {
        this.WalkForParents(root, new List<TreeNode>());
    }

    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
    {
        this.WalkForParents(root);
        var pParents = this._nodeParentsMap[p.val];
        var qParents = this._nodeParentsMap[q.val];

        // disticnt
        return pParents.Intersect(qParents).FirstOrDefault();
    }

    public void PrintParentList()
    {
        foreach (var kv in this._nodeParentsMap)
        {
            System.Console.WriteLine($"{kv.Key}");
            foreach (var item in kv.Value)
            {
                System.Console.WriteLine($"\t{item.val}");
            }
        }
    }

    private void WalkForParents(TreeNode root, List<TreeNode> list)
    {
        if (root == null)
        {
            return;
        }

        // add self.
        var parentList = new List<TreeNode>();
        parentList.Add(root);
        parentList.AddRange(list);
        this._nodeParentsMap[root.val] = parentList;
        WalkForParents(root.left, parentList);
        WalkForParents(root.right, parentList);
    }


}

public class Solution
{
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
    {
        var cal = new LcaCalculator();
        cal.WalkForParents(root);
        cal.PrintParentList();

        return cal.LowestCommonAncestor(root, p, q);
    }

    public TreeNode Get(TreeNode root, int val)
    {
        if (root == null)
        {
            return null;
        }
        //System.Console.WriteLine($"Get: root:{root.val} val:{val}");
        if (root.val == val)
        {
            return root;
        }

        var node = Get(root.left, val);
        if (node == null)
        {
            node = Get(root.right, val);
        }

        return node;
    }

    public TreeNode Build(int?[] values)
    {
        if (values == null || !values.Any())
        {
            return null;
        }

        Queue<TreeNode> nodes = new Queue<TreeNode>();
        var root = new TreeNode(values[0].Value);
        nodes.Enqueue(root);
        var nodeIndex = 1;

        while (nodes.Count > 0)
        {
            var node = nodes.Dequeue();
            if (nodeIndex < values.Length && values[nodeIndex] != null)
            {
                node.left = new TreeNode(values[nodeIndex].Value);
                nodes.Enqueue(node.left);
            }
            nodeIndex++;
            if (nodeIndex < values.Length && values[nodeIndex] != null)
            {
                node.right = new TreeNode(values[nodeIndex].Value);
                nodes.Enqueue(node.right);
            }
            nodeIndex++;

            System.Console.WriteLine(
                $"node:{node.val}: left:{node.left?.val} right:{node.right?.val}"
            );
        }

        return root;
    }

    public void Print(TreeNode root)
    {
        if (root == null)
        {
            return;
        }
        Queue<TreeNode> nodes = new Queue<TreeNode>();
        nodes.Enqueue(root);
        while (nodes.Count > 0)
        {
            var node = nodes.Dequeue();
            System.Console.Write($"{node.val},");
            if (node.left != null)
            {
                nodes.Enqueue(node.left);
            }
            if (node.right != null)
            {
                nodes.Enqueue(node.right);
            }
        }
    }
}

public class Test
{
    public static void Main(string[] args)
    {
        int?[] values = new int?[] { 3, 5, 1, 6, 2, 0, 8, null, null, 7, 4 };
        int pVal = 5;
        int qVal = 4;
        var sol = new Solution();
        var root = sol.Build(values);
        var p = sol.Get(root, pVal);
        var q = sol.Get(root, qVal);
        if (p == null)
        {
            System.Console.WriteLine($"could not find value for p:{pVal}");
        }
        if (q == null)
        {
            System.Console.WriteLine($"could not find value for p:{qVal}");
        }

        System.Console.WriteLine($"p:{p.val} q:{q.val}");
        var ancestor = sol.LowestCommonAncestor(root, p, q);
        if(ancestor == null)
        {
            System.Console.WriteLine($"Ancector could not found for:{pVal} and {qVal}");
            return;
        }
        System.Console.WriteLine($"Ancector: {ancestor.val}");
        //sol.Print(root);
    }
}
