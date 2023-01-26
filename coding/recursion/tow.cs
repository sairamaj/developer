/*
    Tower of Hanoi

    Towers: A, B, C

    1 disk on A
            Move A, C using B  -> done
    2 disks on A
            Tow(1, A, B, C)
            Move A to C using B
            Tow(1,B, C , A)
    3 disks on A
        Treat as 2 disks (top disks as one unit(1,2) and then another disk(3))
        Tow(2,A,B,C)
        Move A to C using B
        Tow(2,B,C,A)  -> then these 2 disks are nothing but previous steps

    n disks
        Tow(n-1,A,B,C)      again treat as 1+ (n-1 disks)
        Move A,C using B
        Tow(n-1,B,C,A)
*/
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class Disc {
    public Disc (int size) {
        this.Size = size;
    }

    public int Size { get; }
    public void Display () {
        var str = new String ('-', this.Size);
        System.Console.WriteLine ($"\t{str}");
    }
}
class Tower {
    private Stack<Disc> _discs = new Stack<Disc> ();
    public Tower (string name) {
        this.Name = name;
    }

    public string Name { get; set; }
    public void Add (Disc disc) {
        this._discs.Push (disc);
    }
    public Disc Remove () {
        return this._discs.Pop ();
    }
    public void Display () {
        System.Console.WriteLine ($"------ {this.Name}--------");
        foreach (var disc in this._discs) {
            disc.Display ();
        }
    }
}

class TowerOfHanoi {
    private IDictionary<string, Tower> _towers = new Dictionary<string, Tower> ();
    int _discs;
    public TowerOfHanoi (int discs) {

        this._discs = discs;
        var towerA = new Tower ("A");
        var size = 60;
        for (var i = 0; i < discs; i++) {
            towerA.Add (new Disc (size));
            size -= 5;
        }
        this._towers["A"] = towerA;

        this._towers["B"] = new Tower ("B");
        this._towers["C"] = new Tower ("C");

    }

    public void Display () {
        foreach (var tower in this._towers) {
            tower.Value.Display ();
        }
    }

    public int Move () {
        return this.Move (this._discs, "A", "C", "B");
    }
    private int Move (int numberOfDiscs, string from, string to, string aux) {
        if(numberOfDiscs == 0){
            return 0;
        }

        // Move all except 1 to the auxiliary disc
        var count = this.Move(numberOfDiscs-1, from, aux, to);

        count++;
        // Move one disc to destinaton
        var disc = this._towers[from].Remove();
        this._towers[to].Add(disc);

        // Now trea aux tower as main source.
        count += this.Move(numberOfDiscs-1, aux, to, from);
        return count;
    }
}

public class Test {
    public static void Main () {
        var game = new TowerOfHanoi (8);
        game.Display ();
        System.Console.WriteLine("________________________________________");
        int count = game.Move();
        System.Console.WriteLine($"Count:{count}");
        game.Display ();
    }
}
