using System;
using System.Collections.Generic;
using System.Linq;

class WordProblem
{
    public IList<IList<string>> canConstruct(string output, string[] inputs)
    {
        return canConstructInternal(output, inputs, new Dictionary<string, IList<IList<string>>>());
    }

    private IList<IList<string>> canConstructInternal(
        string output,
        string[] inputs,
        IDictionary<string, IList<IList<string>>> memo
    )
    {
        var list = new List<IList<string>>();
        if (String.IsNullOrEmpty(output))
        {
            return list;
        }

        if (memo.TryGetValue(output, out var val))
        {
            return val;
        }

        var ways = new List<IList<string>>();
        foreach (var input in inputs)
        {
            if (output.StartsWith(input))
            {
                var retVal = canConstructInternal(output.Substring(input.Length), inputs, memo);
                if (retVal != null)
                {
                    retVal.Add(new List<string> { input });
                    memo[output] = retVal;
                    foreach (var val1 in retVal)
                    {
                        ways.Add(val1);
                    }
                }
            }
        }

        if (ways.Any())
        {
            memo[output] = ways;
            return ways;
        }
        return null;
    }
}

public static class Test
{
    public static void Main(String[] args)
    {
        var inputs = new string[] { "ab", "abc", "cd", "def", "abcd" };
        var output = "abcd";

        var wp = new WordProblem();
        var list = wp.canConstruct(output, inputs);
        foreach (var l in list)
        {
            System.Console.WriteLine("---------------");
            foreach (var ll in l)
            {
                System.Console.WriteLine(ll);
            }
        }
        Console.WriteLine();
    }
}
