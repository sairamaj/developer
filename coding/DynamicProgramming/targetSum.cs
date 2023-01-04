using System;
using System.Linq;
using System.Collections.Generic;

class SumTest
{
    int[] _array;

    public SumTest(int[] array)
    {
        this._array = array;
    }

    public List<int> CanSumInternal(int target, Stack<int> values)
    {
        if (target < 0)
        {
            return null;
        }
        if (target == 0)
        {
            return new List<int>();
        }

        for (var i = 0; i < this._array.Length; i++)
        {
            var output = CanSumInternal(target - this._array[i], values);
            if (output != null)
            {
                output.Add(i);
                return output;
            }
        }

        return null;
    }

    public List<int> CanSum(int target)
    {
        Stack<int> values = new Stack<int>();
        return this.CanSumInternal(target, values);
    }
}

public static class Test
{
    public static void Main(String[] args)
    {
        var input = new int[] { 12, 13, 14, 15, 5, 3, 4, 8 };
        SumTest s = new SumTest(input);
        var output = s.CanSum(4);
        if (!output.Any())
        {
            System.Console.WriteLine("Not found.");
        }
        else
        {
            foreach (var i in output)
            {
                System.Console.WriteLine($"{input[i]}");
            }
        }
        System.Console.WriteLine();
    }
}
