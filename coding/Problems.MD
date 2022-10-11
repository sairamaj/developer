### Duplicate Zeros
Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

##### My solution
* Using the shift for every occurrence
* Inefficient as multiple shifts

##### LeetCode solution
* Find out possible duplicates
* Start moving the numbers from backwards

### Remove Element
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.
#### My solution
Iterate through the arary and skip with val and then copy rest of them. Written using while loop
##### LeetCode solution
* Use reader and writer pointers. reader point will be moving and whenever equal to val move beyond and copy to writer pointer.
* Had another solution where instead of copying replacing (need to try this solution)


