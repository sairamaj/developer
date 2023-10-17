# Duplicate number strategies
 * Sort and find out
   * time: O(nlogN) space:O(n)
 * Set (using map)
   * time: O(n)  space: O(n)
 * Negative marking
   * get element at position and go to that location and start flipping
   * if number is already -ve then it is duplicate
   ```cmd
    [1,3,3,2]
    [0] -> 1
    go to [1] and flip to negative [1,-3,3,2]
    go to [3] and flip [1,-3,3,-2]
    go to [2] and we have already -ve so duplicate is 3
   ```
   * T: O(n) S:O(1)