using System;
using System.Collections.Generic;
using System.Linq;

public class Test
{
    public static void Main()
    {
        var x = new List<char>(new char[5]).Select(a => 'F').ToList();
        x.ForEach(a => System.Console.WriteLine(a));

        var y = Enumerable.Repeat<char>('T',15).ToList();
        y.ForEach(a => System.Console.WriteLine(a));

    }
}
