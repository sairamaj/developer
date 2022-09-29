### Duplicate Zeros
##### Problem
```cmd
Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.
```
##### My solution
* Using the shift for every occurrence
* Inefficient as multiple shifts

##### LeetCode solution
* Find out possible duplicates
* Start moving the numbers from backwards
