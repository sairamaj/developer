/*
    sum of 6 in [3,4,5,2]

    use 2d array of (index+1) and (sum+1)

    Idea is for each column and row by row whether we can form the given sum(which exists in column)
    ex:
        0 row and sum is 0  (represents empty array [] for 0 which is possible)
        Then we will mark (0,0) as T
        we will walk through this column

        For each row for given column we will see below condition
            whether current value at this column is more than sum then
                we blindly take previous row column value whether it is T/F.
                (As for each row if same column in the previous row is 'T' means current row is possible.(i.e
                the sum is possible whether you take current element or not as previous row satisfies means up
                to that point the sum is possible with subset). )
                i.e for given column: j
                    if num[i-1] > sum(dp(i,j)) (the reason i-1 is our numbers are zero indexed.)
            else
                we will see whether value of (sum-current column value) in previous row is 'T' or not or
                previous row column is 'T' or not. we will take one of the 'T' value.

            Lets walk through 0 column first

                      | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
                0(0)  |   |   |   |   |   |   |   |
                ------------------------------------
                3(1)  |   |   |   |   |   |   |   |
                ------------------------------------
                4(2)  |   |   |   |   |   |   |   |
                ------------------------------------
                5(3)  |   |   |   |   |   |   |   |
                ------------------------------------
                2(4)  |   |   |   |   |   |   |   |
            Lets fill first column (0 sum). we can blindly fill 0th column with 'T' as
            '0' possible with empty row and 0th row with 'F' for sum 1 onwards (as with 0 no sum
            is possinble)
                      | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
                0(0)  | T | F | F | F | F | F | F |
                ------------------------------------
                3(1)  | T |   |   |   |   |   |   |
                ------------------------------------
                4(2)  | T |   |   |   |   |   |   |
                ------------------------------------
                5(3)  | T |   |   |   |   |   |   |
                ------------------------------------
                2(4)  | T |   |   |   |   |   |   |
            Lets fill first column

                      | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
                0(0)  | T | F | F | F | F | F | F |
                ------------------------------------
                3(1)  | T |   |   |   |   |   |   |
                ------------------------------------
                4(2)  | T |   |   |   |   |   |   |
                ------------------------------------
                5(3)  | T |   |   |   |   |   |   |
                ------------------------------------
                2(4)  | T |   |   |   |   |   |   |
            [1,1]
                value: 3 , sum : 1
                as 3>1 we take the previous row column (0,1) which is 'F'
            [2,1]
                value:4, sum: 1
                as 41> the value is of(1,1) which is 'F'

                      | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
                0(0)  | T | F | F | F | F | F | F |
                ------------------------------------
                3(1)  | T | F |   |   |   |   |   |
                ------------------------------------
                4(2)  | T | F |   |   |   |   |   |
                ------------------------------------
                5(3)  | T | F |   |   |   |   |   |
                ------------------------------------
                2(4)  | T | F |   |   |   |   |   |
        Lets walk the 2nd column
            [1,2]  3 > 2  [ 0,2] = 'F'
            ............
            [4,2]  2 is <= 2
                  previous row value is 'F'
                  sum - value = 2-2 is 0
                  go to 0th column of previous row which is [3,0] = 'T'
                  the value is 'T'
                      | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
                0(0)  | T | F | F | F | F | F | F |
                ------------------------------------
                3(1)  | T | F | F |   |   |   |   |
                ------------------------------------
                4(2)  | T | F | F |   |   |   |   |
                ------------------------------------
                5(3)  | T | F | F |   |   |   |   |
                ------------------------------------
                2(4)  | T | F | T |   |   |   |   |
            Lets fill 4 and 5th now
                      | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
                0(0)  | T | F | F | F | F | F | F |
                ------------------------------------
                3(1)  | T | F | F | T | F | F  | F |
                ------------------------------------
                4(2)  | T | F | F | T | T | F  | F |
                ------------------------------------
                5(3)  | T | F | F | T | T | T  | F |
                ------------------------------------
                2(4)  | T | F | T | T | T | T  | T(3,4)|

            logic is:
                if( nums[i-1][j] > sum)
                    dp(i,j) = dp(i-1,j)  (as num > sum the only possibility depends upon prev subset
                else
                    dp(i,j) = dp(i-1,j) | dp(i-1, sum-num[i-1])

*/
#include "iostream"
#include <malloc.h>
using namespace std;

bool **state;
int rows, cols;
void printArray()
{
    cout << "----------------------------" << endl;
    for (auto i = 0; i < rows; i++)
    {
        for (auto j = 0; j < cols; j++)
        {
            cout.width(4);
            cout.fill(' ');
            cout << (state[i][j] ? 'T' : 'F');
        }
        cout << endl;
    }
    cout << "-------------------------------" << endl;
}


void isSumPossible(int *array, int size, int sum)
{
}
void main()
{
    int array[] = {3, 4, 5, 2};
    int size = sizeof(array) / sizeof(int);
    int sum = 6;
    state = (bool **)new bool[size + 1];
    for (int i = 0; i < size + 1; i++)
    {
        state[i] = new bool[sum + 1];
    }

    for (int i = 0; i < size + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            state[i][j] = false;
        }
    }

    for (int i = 0; i < size + 1; i++)
    {
        state[i][0] = true;
    }

    for (int i = 1; i < sum + 1; i++)
    {
        state[0][i] = false;
    }

    rows = size+1;
    cols = sum+1;

    printArray();
}
