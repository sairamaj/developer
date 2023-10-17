/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b


Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
*/

/*
    Strategy:
        Brute Force:
            Allocate array k
            start filling from original array up to first k elements
            after k elements start overwriting with lowest.
        Binary Search
            Get mid
                [1,2,3,4,5,6,7,8,9,10,12,13,14,15,16] target:2
                mid: 8 -> get diff
                    go right
                            get diff  : m:13 : diff(11)
                    go left
                            get diff    m:4    diff(2)
                    sure we ned to use left only
                    [1,2,3,4,5,6,7,8]
                    mid:4
                        diff:2
                    mid:2
                        diff:0
                    we found the closet
                option:1
                    gather k - elements on left
                    start gather k elements on right while checking for the difference.
                    if K is large then this may result in O(n);
                option2:
                    [1,2,3,4,5,6,7,8]  :pos:1
                    [1]  [3,4,5,6,7,8]
                    array 1: mid:1   diff:1
                    array 2: mid:5   diff:3
                    so we have left elements close.
                    gather start collecting left elements
                    [1]
                    then start collecting remaining elements on right side.
    example1:
        [1,2,3,20,21,22,40,60,61,62,80,100]
          target:2 k:4
          left mid:22: diff: 20
          left:[1,2,3,20,21,22]
            3: diff:1
          right:[40,60,61,62,80,100]
            61: diff:59
        left is close
            [1,2,3,20,21,22]
            left of 3:[1,2] mid:1  diff:1
            right of 3[20,21,22] mid: 21: diff:21
        left is close
            we found element:
    







*/

#include <stdio.h>
#include <math.h>

void assert(char *msg, int expected, int actual)
{
    if (expected != actual)
    {
        printf("[err] %s expected:%d actual:%d\n", msg, expected, actual);
    }
    else
    {
        printf("[success] %s expected:%d actual:%d\n", msg, expected, actual);
    }
}

int findClose(int *array, int size, int target)
{
    // pseudo code
        // get mid: (l=0; h=size)
        // get diff with target.
            // go left and get diff
            // go right and get diff
            // pick left/right based on low diff
            // go top and repeat
    int l=0, h=size;
    while(l < h){
        printf("l:%d h:%d\n",l,h);
        int mid = l + (h-l)/2;
        int diff = abs(array[mid]-target);
        if(diff == 0){
            return mid;     // 0 is the closet we can get

        }

        int leftMid = l + (mid-l)/2;
        printf("leftMid:%d\n", leftMid);
        int ldiff = abs(array[leftMid]-target);
        printf("array[leftmi]:%d\n", array[leftMid]);

        int rightMid = mid + (h-mid)/2;
// 1-1 + 2
// 4-1 = 5
        printf("rightMid:%d\n", rightMid);
        int rdiff = abs(array[rightMid]-target);
        printf("array[rightMid]:%d\n", array[rightMid]);

        printf("ldiff:%d rDiff:%d diff:%d\n", ldiff, rdiff, diff);
        if(abs(ldiff-diff) < abs(rdiff-diff)){
            // keep left;
            h = mid;
        }else{
            l = mid;
        }
    }

    return array[l];
}
int *findClosestElements(int *arr, int arrSize, int k, int x, int *returnSize)
{
    int element = findClose(arr,arrSize,x);
    printf("element:%d\n", element);
    *returnSize = 0;
    return NULL;
}

void test1()
{
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(int);
    int retSize = 0;

    int *retArray = findClosestElements(array, size, 4, 3, &retSize);
    assert("test1:(4,3)", 4, retSize);
}

void test2()
{
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(int);
    int retSize = 0;

    int *retArray = findClosestElements(array, size, 4, -1, &retSize);
    assert("test2:(4,-1)", 4, retSize);
}

void main()
{
    test1();
    test2();
}