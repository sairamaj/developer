<details>
    <summary>Two sum</summary>

  <details>
    <summary>Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.</summary>
  </details>

  <details>
    <summary>Logic</summary>

```python
   # Two loops:  
   #        # Time: O(n^2) Space:O(1)

   # With Map:
   #        # Time: O(n) Space:O(n)
```
  </details>

  <details>
    <summary>Code</summary>

```python

# Time: O(n^2) Space:O(1)
def two_sum_brute_force(nums: list[int], sum : int) -> list[int]:
    ret = []
    
    for i in range(len(nums)):
        remain = sum - nums[i]
        for k in range(len(nums)):
            if i!=k and nums[k] == remain:
                return [i,k]    

# Time: O(n) Space:O(n)
def two_sum_with_map(nums: list[int], sum : int) -> list[int]:
    map = {}
    
    for i in range(len(nums)):
        remain = sum - nums[i]
        # check in map
        if  remain in map:
            return [map[remain], i]
        map[nums[i]] = i
    return None

print(two_sum_brute_force([2,7,11,15], 9))
print(two_sum_brute_force([3,2,4], 6))

print('----------------')
print(two_sum_with_map([2,7,11,15], 9))
print(two_sum_with_map([3,2,4], 6))

```
  </details>
</details>

____

<details>
  <summary>Remove duplicate in sorted array</summary>

  <details>
      <summary>Logic</summary>
  </details>

```python
# remove duplicate in sorted array
# [0,0,1]  -> [0,1,_]

# Logic
# prev = first element
# [0,0,0,1,2]
# 2 indices , i,j
# keep moving j till num[i] != num[j]
# copy j to i+
# move i
# repeat

# [0,0,0,1,2]
# i =0 , j =3
# [0,1,0,1,2]
# [0,1,2,1,2]

# [1,2,3]
# i=0, j=1
```
  <details>
      <summary>Code</summary>

```python
def remove_duplicate_in_sort(nums : list[int]) -> int:
    cur = nums[0]
    
    i=0
    size = 1
    for j in range(1,len(nums)):
        if nums[j] != nums[i]: 
            i += 1
            nums[i] = nums[j]
            size += 1
            
    print(nums)
    return size            
            

print(remove_duplicate_in_sort([0,0,0,1,2]))
print(remove_duplicate_in_sort([0,0,1,1,1]))


```
  </details>


</details>

___

<details>
  <summary>Remove element from array</summary>

  <details>
    <summary>Logic</summary>

```python
# Logic
#   Strategy1: Overwrite the matching element with non matching element at the right.
#   if not matching copy
#       [1,2,3,4,4,4,5,6]  element:4
#       [1,2,3,]   i:6   
#       [1,2,3,5]
#       [1,2,3,5,6]
#   
#   Strategy 2: Moving from beging and ending and swapping elements with matching and non matching technique
#   keep moving i till it matches with element
#   keep moving j till it does not match with element
#   swap
#   [3,3,2,2,3] i:0 j:5
#   [3,3,2,2,3] i:0 j:4  swap : [2,3,2,3,3] : move i till it maches, move j till it does not match
#   [2,3,2,3,3] i:1 j:2  swatp: [2,2,3,3,3] : 
#   once i  crosses j, we are done.

```
  </details>

  <details>
    <summary>Code</summary>

```python
# https://walkccc.me/LeetCode/problems/0027/#__tabbed_1_3
def remove_element2(nums: list[int], val: int) -> int:
    i = 0

    for num in nums:
      if num != val:
        nums[i] = num
        i += 1

    return i

def remove_element(nums : list[int], element : int) -> int:
    
    i=0; j=len(nums)-1
    
    num_swaps = 0
    while i<j:
        while i<len(nums) and nums[i] != element:
            i += 1
        while j>0 and nums[j] == element:
            j -= 1
        # swap
        
        if i<len(nums) and j>0:
            temp = nums[j]
            nums[j] = nums[i]
            nums[i] = temp
        
        i+=1
        j-=1

    return i
            
def test_remove(nums : list[int], element : int):
    print(f'{nums}  : {element}')
    print('---------------')
    ret = remove_element2(nums,element)
    print(nums[:ret])
    print('____________________')

test_remove([3,3,3,2,2,2], 3)
test_remove([3,3,3,3,3,3],3)
test_remove([3,3,3,2,2,2], 5)
test_remove([1,2,3,4,5,10,10, 6,7,8,9], 10)

```
  </details>

</details>