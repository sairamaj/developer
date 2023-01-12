/*
    Using the bins and based on digit value , the numbers are placed in bins
    Need to pass based number of digits.

    ex:
        237,146,259,348,152,163,235,48,36,62

        create array of 10 (based on number system as this one is decimal. If it is binary we need only size: 2)
        |0|0|0|0|0|0|0|0|0|0|

        each element start taking last digit
            (237/1)%10 = 7
            add in to the bin at position 7
        One all are done take from the bin and this time take next digit
            (237/10)%10 = 7
            add it to the bin
        Take the elements and do take next digit.

        after 3 passes the elements should be in sorted order.
*/
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class Bin {
    IDictionary<int, List<int>> _items = new Dictionary<int, List<int>> ();
    int _radix;
    public Bin (int radix) {
        this._radix = radix;
        this.Reset ();
    }
    public void Add (int index,int val) {
        this._items[index].Add (val);
    }
    public int[] Get () {
        var list = new List<int> ();
        for (int i = 0; i < this._radix; i++) {
            list.AddRange (this._items[i]);
        }

        return list.ToArray ();
    }

    public void Reset () {
        for (int i = 0; i < this._radix; i++) {
            this._items[i] = new List<int> ();
        }
    }
}

class RadixSorter {
    public int[] Sort (int[] array) {
        int k = 1;
        bool process;

        var bin = new Bin (10);
        do {
            bin.Reset ();
            process = false;
            foreach (var val in array) {
                int binPos = (val / k) % 10;
                if (binPos != 0) {
                    process = true;
                }
                bin.Add (binPos, val);
            }

            // Reset
            array = bin.Get ();
            k *= 10;
        } while (process);

        return bin.Get ();
    }

    public void PrintArray (int[] array) {
        array.ToList ().ForEach (a => System.Console.WriteLine ($"{a},"));
    }
}

public class Test {
    public static void Main () {
        RadixSorter sorter = new RadixSorter ();
        var array = new int[] { 237, 146, 259, 348, 152, 163, 235, 48, 36, 62 };
        sorter.PrintArray (array);
        var sorted = sorter.Sort (array);
        System.Console.WriteLine ("___________________");
        sorter.PrintArray (sorted);
    }
}