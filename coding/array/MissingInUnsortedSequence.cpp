/*
    Missing element in sequence of unsorted numbers.
*/
/*
    get min: and max.
    use array to mark
    ex:
        3, 2, 1, 5, 7, 6
        min:1 max:7
        array:
            -1 -1 -1 -1 -1 -1 -1
            1   1  1     1  1  1
        go through array and find which has -1
        missing element is: -1 index + (min value )
*/

#include <stdio.h>
#include <malloc.h>

void main()
{
    //int array[] = {3, 2, 1, 5, 7, 6};
    int array[] = {13, 12, 11, 15, 17, 16};

    int min = array[0];
    int max = array[0];
    int size = sizeof(array) / sizeof(int);
    int* map = new int[size];
    for (int i = 0; i < size; i++)
    {
        if(array[i] < min){
            min = array[i];
        }
        
        if(array[i] > max){
            max = array[i];
        }
        map[i] = -1;
    }

    for(int i=0; i<size; i++){
        map[array[i]-min] = 1;
    }

    // find -1;
    for(int i=0; i<size; i++){
        if(map[i] == -1){
            printf("%d\n", i+min);
        }
    }
}