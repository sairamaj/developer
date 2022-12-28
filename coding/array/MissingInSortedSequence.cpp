/*
    Missing element in sequence of sorted numbers.
    ex:
        1,2,3,5,6,7
        missing: 4
*/
/*
    use difference method.
        - 1,2,3,5,6,7
        - diff of first element with index is : 1       (1-0 = 1)
        - diff of second element with its index is: 1   (2-1 = 1)
        - diff of 3rd element with its index is: 1      (3-2 = 1)
        - diff of 4th element with its index is: 1      (5-3 = 2)
            - missing element is 4 (3+1)
*/
#include <stdio.h>

int getMissingOfUnsortedArray(int *array, int size)
{
    if (size == 0)
    {
        return -1;
    }

    int diff = array[0];
    for (int i = 1; i < size; i++)
    {
        if( array[i]-i != diff){
            return diff+i;
        }
    }
}
void main()
{
    int array[] = {1, 2, 3, 5, 6, 7};
    int missing = getMissingOfUnsortedArray(array,sizeof(array)/sizeof(int));
    printf("missing:%d\n", missing);

    int array1[] = {11, 12, 13, 15, 16, 17};
    int missing1 = getMissingOfUnsortedArray(array1,sizeof(array1)/sizeof(int));
    printf("missing:%d\n", missing1);

}