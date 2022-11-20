using System;
using System.Collections.Generic;
using System.Linq;

class Test
{
    public static void Main()
    {
        var array = new List<int> { 4, 1, 2, 5, 6, 7 };
        Console.WriteLine("Before...");
        array.ForEach(a => Console.WriteLine(a));
        array = array.OrderBy(a => a).ToList();
        Console.WriteLine("After...");
        array.ForEach(a => Console.WriteLine(a));

    }
}
