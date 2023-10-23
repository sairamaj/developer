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
	* Note: Hash tables access O(1) as long as no collision (if a collision occurred, a lookup could degenerate to O(n)O(n) time)
)
_______	

* atoi
  * consider all cases
  * walk through each character by character and start adding
  * ex:
     ```cmd
	     "432"
		 4
		 4*10 + 3 = 43
		 
		 43*10 + 2 = 432
     ```	 
	* for overflows
	  * see if we can use long (for int)
	  * if we can't use long and only has to int then we need to make sure overflow does not happen
		```cmd
			if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) { 
                // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.    
                return sign == 1 ? INT_MAX : INT_MIN;
            }
		```
  * Deterministic Finite Automaton
    * Using Dfs one can solve this using state machine
	* [youtube](https://www.youtube.com/watch?v=PK3wL7DXuuw&list=PLhqug0UEsC-IDomfNsn8e3neoy34o8oye&index=3)
__________________________

* Reverse word a string
  ```cmd	
	Input: s = "the sky is blue"
	Output: "blue is sky the"
  ```
  
  * brute force
	* walk through back
	```cmd
	* ptr1 = e
	  ptr2 = b
	  copy (ptr2-ptr1) to new strnig = "blue";
	  move ptr1 = s
	  move ptr2 = i
	  copy (ptr2-ptr1) to new strnig = "is";
	* Complexity
		O(n)  space: O(n)
  * in place
    * reverse the whole string
    * reverse the word in place 
    * trim the white space.
	
__________________________________________

* Valid parenthesis
  ```cmd
      Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
		An input string is valid if:
		Open brackets must be closed by the same type of brackets.
		Open brackets must be closed in the correct order.
		Every close bracket has a corresponding open bracket of the same type.
  ```
  * approach-1
	* use stack
	* if '(','{','[' push
	* if you see ')' , '}', '[' then pop on top of stack
	* compare whether it is complement one 
	* if not it is invalid
	* ex:
		```cmd
			(())
			push '(', '('
			for ')' pop and see ')'
			for ')' pop and see whether it is ')'
	```

_______________________________________________

* Anagrams 
  ```cmd
	Given an array of strings strs, group the anagrams together. You can return the answer in any order.
	An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
	
	Input: strs = ["eat","tea","tan","ate","nat","bat"]
	Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
  ```
  * Brute force
    * go throuh each one
		check anagram or not
			add this to list
			remove from list.
		add current
  
	
  


