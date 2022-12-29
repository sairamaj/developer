/*
Serialization is the process of converting a data structure or object into a sequence of bits 
so that it can be stored in a file or memory buffer, or transmitted across a network connection 
link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction 
on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
*/

/*
    Strategy:
        Use comma separated tree,
        Use in order
            [1,2,3,null,null,4,5]
        Construct
            start from first node
            create root node
            go to the next and create and attach it to left
            go to the next and create and attach it to right
        Serialize

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

public class Builder
{
    int curIndex;
    int?[] values;
    public Builder(string input){
        if(string.IsNullOrWhiteSpace(input)){
            return;
        }
        
        //System.Console.WriteLine($"input:|{input}|");
        this.values = input.Trim(',').Split(',').Select<string,int?>(s => {
            if(s == "null"){
                return null;
            }
            //System.Console.WriteLine($"convert: |{s}|");
            return Convert.ToInt32(s);
        }).ToArray();
    }
    public Builder(int?[] values)
    {
        this.values = values;
    }

    public TreeNode Build()
    {
        if (this.values == null || !this.values.Any())
        {
            return null;
        }

        return this.BuildInternal();
    }

    private TreeNode BuildInternal()
    {
        if (curIndex >= values.Length || values[curIndex] == null)
        {
            return null;
        }

        var root = new TreeNode(values[curIndex].Value);
        curIndex++;
        root.left = this.Build();
        curIndex++;
        root.right = this.Build();

        System.Console.WriteLine($"root:{root?.val} left:{root.left?.val} right:{root.right?.val}");
        return root;
    }
}

public class Codec
{

    public TreeNode Build(int?[] values)
    {
        return new Builder(values).Build();
    }


    public void Print(TreeNode node)
    {
        if (node == null)
        {
            System.Console.Write("null,");
            return;
        }

        System.Console.Write($"{node.val},");
        Print(node.left);
        Print(node.right);
    }

    // Encodes a tree to a single string.
    public string serialize(TreeNode root)
    {
        if(root == null){
            return "null,";
        }

        var data = root.val.ToString();
        data += ",";
        data += serialize(root.left);
        data += serialize(root.right);

        return data;
    }

    

    // Decodes your encoded data to tree.
    public TreeNode deserialize(string data)
    {
        return new Builder(data).Build();
    }
}

public class Test
{
    public static void Main(string[] args)
    {
        Codec ser = new Codec();
        Codec deser = new Codec();
        var root = ser.Build(new int?[] { 1, 2, 3, null, null, 4, 5 });
        System.Console.WriteLine(ser.serialize(root));
        TreeNode ans = deser.deserialize(ser.serialize(root));
        ser.Print(ans);
        
        //ser.Print(root);
    }
}
