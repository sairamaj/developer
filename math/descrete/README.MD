# Decrete math
* Not continuous
* well defined set.

## Set
* Empty set
* Single Set
* Subset
* Power set
  * All subsets (2^n)
  * ex: {1,2}
  * {{}, {1},{2} , {1,2}}  (2^2=4)
* Operations
  * Union
  * Intersection
  * Difference
  * Cartisian Product
    * {1,2}{3,4}
    * { (1,3), (1,4), (2,3), (2,4)}
* Mathematical Induction
 * P(1) is true 
 * P(k+1) is true if P(k) is true
* Principle of Inclusion and Exclusion
  ```cmd
    n(A1 U A2) = n(A1) + n(A2) - n(A1 ∩ A2)
    n(A1 U A2 u A3) = n(A1) + n(A2) + n(A3) - n(A1 ∩ A2) - n(A2 ∩ A3) - n(A3 ∩ A1) + n(A1 ∩ A2 ∩ A3)
  ```

* Piegon Principle
  * if (N+1) or more objects in N boxes , then there is one box containing at least two or more objects.
  * if 'n' piegons are occupted by kn+1 or more piegons then at least one piegon hole is occupied by k+1 or more piegons.
  ```cmd
  Prob:
    Find the minimum number of teaches in a college to be sure that four of them are born in same month.
      n=12 (holes)
      k+1 = 4 ; k =3
      kn+1 = 3*12+1 = 37
      proof:  37/12 = 3 (with 1 reminder)
  ```
  ```cmd
    A box contains 10 blue balls , 20 red balls, 8 green balls, 15 yellow balls, and 25 white balls.How many balls we must choose to ensure that we have 12 balls of the same color.

    k+1 = 12  ,k=11
    n = 5 (holes)
    11*5+1 = 56
  ```
  ```cmd
    if we allot 26 rooms to the students in hostel from the room number 1, 50 both inclusive
    then at least two allotments are consecuitive.
      50/26 => 1
    ex:if we have 10 rooms and we allot 6 then there will be at least 2 rooms next to each other
    1  3  5  7 9  . now the 6th room has to go next to one of the existing.
  ```
* Some exercies
  * If theater has 1300 seats how many seats need to be filled up to ensure that these 2 people of the same first and last initial?

  [exercises](https://www.youtube.com/watch?v=pPuvnD4PYNE)

  [prove that amount 5 integers, you can pick 3 of them such that their sum is divisible by 5](https://www.youtube.com/watch?v=2leHFuMKr9o)
  

  #### Greatest Integer function
  * [x] -> the greatest integer less than or equal to x
  ex: [0.5] -> 0 , [2] => 2 , [-3] => -3 (rounds down) , [-1.2] => [-2]