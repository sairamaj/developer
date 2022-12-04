/*
    You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
    Increment the large integer by one and return the resulting array of digits.

    Example 1:

        Input: digits = [1,2,3]
        Output: [1,2,4]
        Explanation: The array represents the integer 123.
        Incrementing by one gives 123 + 1 = 124.
        Thus, the result should be [1,2,4].
    Example 2:

        Input: digits = [4,3,2,1]
        Output: [4,3,2,2]
        Explanation: The array represents the integer 4321.
        Incrementing by one gives 4321 + 1 = 4322.
        Thus, the result should be [4,3,2,2].
    Example 3:
        Input: digits = [9]
        Output: [1,0]
        Explanation: The array represents the integer 9.
        Incrementing by one gives 9 + 1 = 10.
        Thus, the result should be [1,0].
*/
/*
    Strategy:
        Intution:
            - Brute force
                - Convert to real integer
            - This is not real inteteger as the length of array is 100.
            - So cannot be done this way
        2nd Thought
            - Start from right 
            - Add 1 to it
            - Take carry over
            - Go left and add carry over
            - At the end of the loop 
               - if carry over
               - add it to 1
            - Edge cases
                - do we allocate extra 1
                - we will not be knowing whether we need extra 1 or not till end
        leet code
            - sentinel node

Status: Need to come back and finish. 


*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){

}