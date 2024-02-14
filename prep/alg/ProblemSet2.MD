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