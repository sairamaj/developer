## Check a given number is Power of 2

<details>

  <summary>Brute Force</summary>
  
  ```python
  n = 120

  x = n
  while x > 1:
    if x %2 == 0:
      x = x/2
    else:
      break


  if x==1 :
      print(f"{n} :yes power of 2")
  else:
      print(f"{n} No it is not")
  ```

</details>

<details>

  <summary>Bitwise And</summary>

  ```python
      ( x & (x-1) ) == 0
  ```

</details>

<details>

  <summary>By Counting Bits</summary>
     
  * There should be only one bit count
  * ex
    ```txt
      2  -> 10
      4  -> 100
      8  -> 1000
    ```

    ```python
    n = 1024
    x = n
    bit_count = 0
    for i in range(16):
      if x&1 == 1:
        bit_count +=1
        # optionaly we can bail out here, if >1
      x = x>>1

    print(f"bit count;{bit_count}")
    if bit_count > 1:
      print(f"{n} is not a power of 2 , as bit_count is:{bit_count}")
    else:
      print(f"{n} is power of 2")
      
    ```

</details>

<details>

  <summary>Log2</summary>
    
  ```python
  y = math.log2(x)
  if math.floor(y) == math.ceil(y):
    print("power of 2)
  ```

</details>

___

## Finding a Needle in Heystack

<details>
   <summary>Two Loops</summary>
   
   <details>
      <summary>Logic</summary>

* Loop through hey stack
* Loop through neele stack
  * Check each match
    * If no match break
    * Check reached at the end of needle
    * If reached, return hey stack index.

   </details>

   <details>
     <summary>Code</summary>
```python
# sabsad
# sad
# 
def find_needle_in_heystack(hey_stack, needle):
    h = len(hey_stack)
    n = len(needle)

    for i in range(h):
        
        # start from current i
        j = i
        for k in range(n):
            if hey_stack[j] == needle[k]:
                # matched keep moving
                j = j+1
            else:
                break
            
            # check whether we have reached to last index of the needle
            if k == n-1:
                return i
   
    return -1

pos = find_needle_in_heystack("sasad", "sad")
print(f'needle position: {pos}')

pos = find_needle_in_heystack("leetcode", "leeto")
print(f'needle position: {pos}')

```
   </details>
</details>

____

## Ransom Notes

<details>

  <summary>Can ransome notes be constructed from magazine</summary>

  <details>
     <summary>info</summary>

* ransomNotes can be constructed from the letters in magazine. Letters in magazine can be used only once.
* ex: "aa" can be constructed from "aab"
* "aab" cannot be constructed from "ab"
* [source](https://www.youtube.com/shorts/7IyE3RgHap0)
  </details>
  
  <details>
  <summary>Code</summary>

```python
def canConstruct(ransom :str, magazine : str) -> bool:
    letters = {}
    
    # load leters in to dictionary
    for l in magazine:
        if l in letters:
            letters[l] += 1     # increment
        else:
            letters[l] = 1
    #print(letters)
    
    # check from ransom whether each letter contains in letters
    for c in ransom:
        if c not in letters:
            return False        # return immeidatley as we cannot construct
        if letters[c] == 1:
            del letters[c]      # if there is only 1 , delete from dictionary
        else:
            letters[c] -= 1
    
    return True     # we come here means we have all the letters to construct ransom
            

ransomNote = "ab"
magazine = "aab"
ret = canConstruct(ransomNote, magazine)
print(f"can construct {ransomNote} from {magazine}  {ret}")

```

</details>


</details>

____

## Longest Common Prefix
<details>
  <summary>Function to find the longest common prefix strings amongst any array of strings</summary>
<details>
    <summary>Logic</summary>

```python
# Pick a item from the list and start looking for each chacter in all the string to match
#       2 straties to pick
#           first one
#           go through list and find out the minimum one.
#   For each character in selected item
#       For each string 
#           If no match
#               return result
#       append to result
#   return result```
```
  </details>

  <details>
    <summary>Code</summary>

```python
def longest_prefix(strs : list[str]) -> str:
    result = ""
    
    for i in range(len(strs[0])):
        for s in strs:
            if len(s) == i or strs[0][i] != s[i]:
                return result
        result += strs[0][i]

    return result



print(longest_prefix(['flower','flight', 'flow']))
print(longest_prefix(['flower', 'flow']))

```

  </details>
</details>

____

## Last word length

<details>
  <summary>Get the last word length (exluding spaces)</summary>

   <details>
      <summary>Logic</summary>

```python
# go through backwards of string using (range(start,stop,step))
# skip to the first non white space in reverse
# In next loop keep counting till white space occurs
# return count
```

   </details>

  <details>

   <summary>Code</summary>

```python
def last_world_length(str1 : str) -> int:
    count = 0
    str_length = len(str1)-1
    
    # Skip to up to non white space
    for i in range(len(str1)-1,-1,-1):
        if str1[i] != ' ':
            break
        str_length -= 1
            
    for i in range(str_length,-1,-1):
        if str1[i] == ' ':
            return count
        count += 1
    return count

print(last_world_length("Hello World123   "))
print(last_world_length("Hello World123"))
print(last_world_length("Hello"))
print(last_world_length("    "))

```



  </details>

</details>
