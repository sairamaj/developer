/*
    Zonal Computing Olympiad 2014, SUPW
    input:
        10
        mins: [3,2,1,1,2,3,1,3,2,1]
        condition:
            No student can go three days ina  row without any SUPW activity
        question:
            find minimum minutes one can spend.
*/

/*
    strategy:
        start with day 1,2,3  (we need not take 4th to start with)
                3          2      1
        for each recusively walk through to get each day how many mins
                3[3,2,1,1,2,3,1,3,2,1]      [1,1,2,3,1,3,2,1]
                                             (0,1,4,7)(0,2,5,8)
        total:
                            [0,1,2]

            [0,1,4,7]         [1,2,5,8]         [2,3,6,9]
            [0,2,5,8]         [1,3,6,9]         [2,4,7]
            [0,3,6,9]         [1,4,7]           [2,5,8]

            
            [2,3,4,7]

            greedy approach
                - go with 3 day window and pick minimum
                - once you pick min, find the next 3 day window and get min again.
                - may not work always.
*/
#include <stdio.h>

int findMin(int array[], int start, int size)
{
}
int findMin(int array[], int size)
{

    int min = 1000;

    for (int i = 0; i < 2; i++)
    {
        int val = findMin(array, 0, size);
        if (val < min)
        {
            min = val;
        }
    }
    return min;
}

void main()
{
    int array[] = {3, 2, 1, 1, 2, 3, 1, 3, 2, 1};
    int size = sizeof(array) / sizeof(int);
    findMin(array, size);
}