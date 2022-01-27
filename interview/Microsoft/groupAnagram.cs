using System;
using System.Collections.Generic;

public class Solution
{
    // ["eat","tea","tan","ate","nat","bat"]
    // [["bat"],["nat","tan"],["ate","eat","tea"]]
    public IList<IList<string>> GroupAnagrams(string[] strs)
    {
            var list = new List<IList<string>>();
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

            foreach(var kv in dict)
            {
                var anagarams = new List<string>();
                foreach(var l in kv.Value)
                {
                    anagarams.Add(l);
                }
                list.Add(anagarams);
            }

            return list;
    }
}

namespace Exercise
{
    class Test
    {
        public static void Main()
        {
            string[] strs = new string[] { "eat", "tea", "tan", "ate", "nat", "bat" };
            Solution sl = new Solution();
            var list = sl.GroupAnagrams(strs);
            foreach(var l in list){
                foreach(var a in l){
                    Console.WriteLine(a);
                }
                Console.WriteLine("________________________________");
            }
        }
    }
}
