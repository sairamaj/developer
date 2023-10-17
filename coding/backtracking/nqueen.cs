/*
    0  0  0  0
    0  0  0  0
    0  0  0  0
    0  0  0  0
                Fill(0)
                base
                    if no more rows
                        return
            Possible?(mark)
                1,0,0,0
            If not TryFill Next
            
        Fill(1)
          Possible()
            No
            Go back
       Fill(2)
     Fill(3)
    Fill(4)
      
                [1,0,0,0]   
                    
            Fill(1)
              [0,0,1,0]
                 [0,0,0,1]
                   [0,1,0,0]
                    
              Fill(2)
                not possible

              



        
*/
using System;

class QueenGame
{
    int[][] _array;

    public QueenGame(int n)
    {
        this._array = new int[n][];
        for (var i = 0; i < n; i++)
        {
            this._array[i] = new int[n];
        }
    }

    public void Display(String title)
    {
        System.Console.WriteLine($"-------- {title} ------------");
        for (var i = 0; i < this._array.Length; i++)
        {
            for (var j = 0; j < this._array.Length; j++)
            {
                System.Console.Write($"{this._array[i][j], 4} ");
            }
            System.Console.WriteLine();
        }
        System.Console.WriteLine("------------------------------");
    }

    public bool Fill(int row)
    {
        if (row >= this._array.Length)
        {
            return true; // no more rows.
        }
        this.Display($"Before fill:{row}");
        var success = false;
        for (int col = 0; col < this._array.Length; col++)
        {
            if (IsPossible(row, col))
            {
                this._array[row][col] = 1;
                if (!Fill(row + 1))
                {
                    // looks like next row is not possible.
                    this._array[row][col] = 0;
                    // Move on to next column and try again.
                }
                else{
                    return true;
                }
            }
            else{
                // try next one.
            }
        }

        return false;
    }

    private bool IsPossible(int curRow, int curCol)
    {
        System.Console.WriteLine($"checking for {curRow}:{curCol}");
        // look for vertical
        // ex: if we are in 3,3
        // look for (0,3)(1,3)(2,3)
        for (var i = 0; i < curRow; i++)
        {
            // check queen already filled in this column
            if (this._array[i][curCol] == 1)
            {
                System.Console.WriteLine($"column: {i}:{curCol} not possible.");
                return false; // already queen in previous columns
            }
        }

        // look for diagnonal
        // ex: if we are (2,2)
        // (1,1)(0,0)  (\)
        // (1,3)(0,4)   (/)
        for (int row = curRow - 1, col = curCol - 1; row >= 0 && col >= 0; row--, col--)
        {
            if (this._array[row][col] == 1)
            {
                System.Console.WriteLine($"First diagonal : {row}:{col} not possible.");
                return false; // already in diagnoal exits.
            }
        }
        for (
            int row = curRow - 1, col = curCol + 1;
            row >= 0 && col < this._array.Length;
            row++, col++
        )
        {
            if (this._array[row][col] == 1)
            {
                System.Console.WriteLine($"Second diagonal : {row}:{col} not possible.");
                return false; // already in diagnoal exits.
            }
        }

        System.Console.WriteLine($"{curRow}:{curCol} possible.");
        return true;
    }

    private int GetNextColToTry(int row)
    {
        // try getting 1
        for (var i = 0; i < this._array.Length; i++)
        {
            if (this._array[row][i] == 1)
            {
                return i + 1;
            }
        }

        return 0; // no 1 found means start from 0.
    }
}

class Test
{
    public static void Main()
    {
        var game = new QueenGame(4);
        game.Display("Begin");
        game.Fill(0);
        game.Display("End");
    }
}
