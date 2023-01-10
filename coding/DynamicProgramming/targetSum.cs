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

    public IList<int> CanSumInternal(int target, IDictionary<int, IList<int>> values)
    {
        if (values.TryGetValue(target, out var val))
        {
            return val;
        }
        if (target < 0)
        {
            return null;
        }
        if (target == 0)
        {
            return new List<int>();
        }

        IList<int> shortest = null;
        for (var i = 0; i < this._array.Length; i++)
        {
            var output = CanSumInternal(target - this._array[i], values);
            if (output != null)
            {
                output.Add(i);
                if (shortest == null || output.Count < shortest.Count)
                {
                    shortest = output;
                }
            }
        }

        return shortest;
    }

    public IList<int> CanSum(int target)
    {
        var values = new Dictionary<int, IList<int>>();
        return this.CanSumInternal(target, values);
    }
}

public static class Test
{
    public static void Main(String[] args)
    {
        //var input = new int[] { 2, 3, 4, 12, 13, 14, 15, 5, 3, 4, 8 };
        var input = new int[] { 1, 4, 5 };
        SumTest s = new SumTest(input);
        var output = s.CanSum(9);
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
