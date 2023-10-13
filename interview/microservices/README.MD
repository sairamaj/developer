# Leet code
* Two Sum
  ```cmd
	Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
	You may assume that each input would have exactly one solution, and you may not use the same element twice.
	You can return the answer in any order.
  ```
  * Brute force
     O(n^2) space: O(1)
  * Using map
    * O(n)  space: O(n)
    * maintain map of item and position
    * at each element find out whether complement value exists in map
    * ex:
      * [3,2,4] - target =6
	  * map
	  ```cmd
	     first:
		 complement : 3 (6-3)
		 [3] -> 0
		 
		second:
			complement: 4 (6-2)
			not found in map
			map:
				[3] -> 0
				[2] -> 1
		third:
			complement: 3 (6-3)
			exists in map at : 0
			ans: [0,2]
	  ```
	
_______	
