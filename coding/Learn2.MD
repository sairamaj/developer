improving linear searach
  - tran
  - moving head
 
 inserting into sorted array
	- we don't have to do binary serach as anyway elements will be shifted. we can start from back and keeping moving appropriae
	
finding missing elements on sequence of sorted numbers. (6,7,8,10,11,12)
	- use sum of natural numbers 
		(n*(n+1))/2
		subtract from sum
		missing element.
	- use the index and its value with different
		if change in difference then missing element.
Counting duplicates
	- sorted array		
			- we don't need mapper for this
			- as elements are sorted we can keep checking adjecent elements.
Findout out a element which is neither min nor max:
	- O(1)
	- Reason is we don't want to find proper min and proper max.
	- we can take 1st 3 elements and get one is neither min nor max 
	- [8,7,5,12,9,3,4]
	- Here 12 is max and 3 is min.
	- and we need any element other than 3 and 12,
	- It is good enough to consider first3 (8,7,5) and pick 7 (neither max:8 nor min:7) which satisfies.
	- Hence the time is: O(1)
	
Bits AND is masking
	Knowing whether a bit is on or not in a memory is called masking. 
	Left shift 1 and ANDing
Bits OR is merging
	Setting a bit in memory is maring
	Left shift 1 and ORing

- Backtrckig is possible with recursion.


* Linked Lists
  * Reversing a single linked list 
	 * Using sliding pointers (r,q,p)
  * Linear linked list - last is null
  * Circular linked list - last connected to first (head)
  * Double linked list is usage in browser where back and forth can be visited.
  
* Stack
  * Recurrsions can be converted to iterations using Stack
  * When using linked list , alwyas insert at Head which makes insert/deletes O(1)
  * Parenthesis matching (ex: ((a+b)* (c*d)) )
  * Infix   (a+b)
  * PostFix  (ab +)
  * Prefix   (+ab)
* Queue
  * Can be implemented usnig 2 stacks.
* Trees
  * Catalan formula
  * Given n , number of tree can be generted is : (2nCn/(n+1))  (for unlabled)
  * Given n , number of tree can be generted is : (2nCn/(n+1))*n!  (for labled)
  * Recursive formula:
  * Max height: (n-1)^2
  * Min nodes from height: n=(h+1)
  * Max nodes from height: 2^(h+1) -1
  * Max Height = n-1
  * Min Height  = log2(n+1)-1
  * Deg(0) = Deg(2)+1
  * Strict Binary Trees
    * Deg 0 or 2 (no Deg 1)
	* Min nodes = 2h+1
	* Max nodes = 2^(h+1)-1
	* e = i+1 (e - external i-internal)
  * Representation
    * Strict binary can be represented as array
	  * Left child: 2*i
	  * Right child 2*i+1
	  * Parent: i/2
  * Full vs Complete
  * Pre and Post order combination cannot generate a unique tree.
  * Pre/Inorder or Post/InOrder combination can give unique tree.
  * Most common operations on tree are done in Post Order.
 * Binary Search Tree(BST)
   * Eleements on left or less and elements on right are more.
   * No duplicates
   * In order traversal gives sorted order.
   * Serach depends on height of tree
   * Log(N) < h < N  (N is the number of nodes)
   * While deleting if root is being deleted
     * Find out In order Predecssor or In order Successor.
   * Either PreOrder or PostOrder is good enough for BST (we don't need In order)
 * AVL Trees 
   * Balance Factor = height of left subtree - height of right subtree
     * bf = hl-hr = { -1,0,1 }
	 * |bf| = |hl-hr| <= 1  balanced
	 * |bf| = |hl-hr| >=    imbalanced
 * Heap
   * Height is Log(N)
   * Complete binrary tree
   * Usually represented by Array
     * Node at index: i
	 * Left child at 2*i
	 * Right child at (2*i)+1
   * In Max heap one delete only max.
 * Hashing
   * Ideal hashing (one to one)
   * Many to Many (collision)
     * Open
	   * Chaining
	 * Closed Hashing
	   * Linear Probing (f(i) = i)
	   * Quadratic Probing (f(i) = i^2)
	 * Double Hashing
	* suggested size of the hash table is prime number.
   * Hash functions
     * Mod
	 * Mid Sqaure
	 * Folding
