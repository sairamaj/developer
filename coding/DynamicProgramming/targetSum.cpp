#include <stdio.h>

bool canSum(int target, int *array, int size, int index = -1)
{
    printf("target:%d\n", target);
    if (target < 0)
    {
        return false;
    }
    if (target == 0)
    {
        printf("index:%d\n", index);
        return true;
    }
    printf("index:%d\n", index);
    bool ret = false;
    for (int i = 0; i < size; i++)
    {
        if (canSum(target - array[i], array, size, i))
        {
            ret = true;
            return true;
        }
    }

    return ret;
}
void main()
{
    int array[] = {5, 3, 8, 2};
    // int array[] = {2, 4 };
    bool ret = canSum(7, array, sizeof(array) / sizeof(int));
    printf("%d\n", ret);
}