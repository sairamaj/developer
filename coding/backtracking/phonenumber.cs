using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {

	/*
		2 - [abc]
		3 - [def]
		4 - [ghi]
		5 - [jkl]
		6 - [mno]
		7 - [pqrs]
		8 - [tuv]
		9 - [wxyz]
	*/

	// ex: 234
	// for each digit
	// get list of letters
	/*
			a    b         c
		d  e   f   d e f    d e f
	  g h i  ghi	ghi
	  
	  adg, adh, aei, aeg, aeh, aei, 
	*/
	
	
	private const int ZeroValue = 48;
	private IDictionary<int,string> _letterToCharMap = new Dictionary<int,string> {
		{ 2, "abc"},
		{ 3, "def"},
		{ 4, "ghi"},
		{ 5, "jkl"},
		{ 6, "mno"},
		{ 7, "pqrs"},
		{ 8, "tuv"},
		{ 9, "wxyz"}
	};
	
	public IList<string> GetCharMapStrings(char ch) 
	{
		int digit = Convert.ToInt32(ch)-ZeroValue;
		if(this._letterToCharMap.TryGetValue(digit, out var map) )
		{
			return map.ToCharArray().Select(c => new String(c,1)).ToList();
		}
		
		return new List<string>();
	}
	
	public IList<string> LetterCombinations(string digits) {
		
		if(string.IsNullOrWhiteSpace(digits))
		{
			return new List<string>();
		}
		
		Console.WriteLine($"LetterCombinations: {digits}");
		if(digits.Length == 1)
		{
			return GetCharMapStrings(digits[0]);
		}
		
        var combinations = new List<string>();
		foreach(var curMap in GetCharMapStrings(digits[0]))
		{
			var restOfString = digits.Substring(1);
			var map = LetterCombinations(restOfString);
			foreach(var charMap in map)
			{
				var s = curMap + charMap;
				combinations.Add(s);
			}
		}
			
		return combinations;
    }
	
	public static void Main()
	{
		foreach(var comb in new Solution().LetterCombinations("2435"))
		{
			Console.WriteLine(comb);
		}
	}
}