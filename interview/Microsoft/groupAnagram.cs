using System;
using System.Collections.Generic;

public class Solution
{
    // ["eat","tea","tan","ate","nat","bat"]
    // [["bat"],["nat","tan"],["ate","eat","tea"]]
    public IList<IList<string>> GroupAnagrams(string[] strs)
    {
        // sort all of them.
        // group by same
        Array.Sort(strs);
        return null;
    }
}

namespace Exercise
{
    class Test
    {
        public static void Main()
        {
            string[] strs = new string[] { "eat", "tea", "tan", "ate", "nat", "bat" };
            System.Console.WriteLine("__________________");
            foreach (var s in strs)
            {
                System.Console.WriteLine(s);
            }
            System.Console.WriteLine("__________________");
            var dict = new Dictionary<string, List<string>>();
            foreach (var s in strs)
            {
                var c = s.ToCharArray();
                Array.Sort(c);
                var x = new string(c);
                if (dict.TryGetValue(x, out var val))
                {
                    dict[x].Add(s);
                }
                else
                {
                    dict[x] = new List<string> { s };
                }
            }

            System.Console.WriteLine("__________________");
            foreach(var kv in dict){
                foreach(var l in kv.Value){
                    System.Console.WriteLine(l);
                }
                System.Console.WriteLine("-------------------------");
            }
            System.Console.WriteLine("__________________");
        }
    }
}
