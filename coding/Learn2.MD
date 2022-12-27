* improving linear searach
  - tran
  - moving head
 
 * inserting into sorted array
	* we don't have to do binary serach as anyway elements will be shifted. we can start from back and keeping moving appropriae
	
* finding missing elements on sequence of sorted numbers. (6,7,8,10,11,12)
  * use sum of natural numbers 
	*	(n*(n+1))/2
	*	subtract from sum
	*	missing element.
	*   use the index and its value with different
	*	if change in difference then missing element.
* Counting duplicates
  * sorted array		
    * we don't need mapper for this
	* as elements are sorted we can keep checking adjecent elements.
* Findout out a element which is neither min nor max:
	- O(1)
	- Reason is we don't want to find proper min and proper max.
	- we can take 1st 3 elements and get one is neither min nor max 
	- [8,7,5,12,9,3,4]
	- Here 12 is max and 3 is min.
	- and we need any element other than 3 and 12,
	- It is good enough to consider first3 (8,7,5) and pick 7 (neither max:8 nor min:7) which satisfies.
	- Hence the time is: O(1)
	
* Bits AND is masking
  * Knowing whether a bit is on or not in a memory is called masking. 
  * Left shift 1 and ANDing
* Bits OR is merging
  * Setting a bit in memory is maring
  * Left shift 1 and ORing
