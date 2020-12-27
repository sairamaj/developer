using System;
using System.Text.RegularExpressions;
					
public class Program
{
	public static void Main()
	{
		Console.WriteLine("Hello World");
		var pattern = @"(?<name>\w+)\/(?<address>\w+.[^\?]*)?(\?last=(?<lastname>\w+))*\|(?<value>.*)";
		var r = new Regex(pattern);
		var inputs = new string[]{
			@"sai/17003 nw tucson st/beaverton/or?last=jamalapuram|value here\r\n additional vaulue",
			@"ram/17004 nw tucson st/beaverton/or|ram value here\r\n additional vaulue",
		};
		
		foreach(var input in inputs)
		{
			var m = r.Match(input);
			Console.WriteLine("_________________________________");
			Console.WriteLine("name=" + m.Groups["name"].ToString());
			Console.WriteLine("address= " + m.Groups["address"].ToString());
			Console.WriteLine("lastname=" +  m.Groups["lastname"].ToString());
			Console.WriteLine("value= " + m.Groups["value"].ToString());
			Console.WriteLine("_________________________________");
		}
	}
}