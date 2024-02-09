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
