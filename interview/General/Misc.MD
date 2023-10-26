* swap without using 3rd variables
  ```c
    a = a-b   
    b = a+b   (a-b+b) = a
    a = b-a  (a-a+b) = b

    ex:
      a=6,4
      a = 2
      b = 6
      a = 4
  ```
  * without addition
    * using XOR
      
    ```cmd
      a = a^b
      b = a^b
      a = a^b

      a=1 b=2
      0001
      0010

      a = 0011
      b = 0011
          0010
          0001

      a = 0011
      a = 0001
          0010
    ```

_________

* backtracking
  * for small values
  * all possible combinations
_______

* finding out poisonous bottle
  * 1000 bottles
  * party to start  10 hours
  * one of the bottle has poisinous.
  * it takes 10 hours for someone to die after consuming
  * how many minimum numer of people needed by king to identity
  * hint : use binary
_______

boat: can take 2 people at a time
A:1 (min), B:2 C:5 D:10
what is mininum time: 17 (min)

_____________________________

Paper folding 42 times

You might say that a paper can't practically be folded more than 7/8 times, but please know that I am presenting a hypothetical situation. I urge you to not miss the beauty of exponential growth by getting into practicality :) CALCULATION: Thickness of a paper = 0.1 mm Thickness when folded one time = 2 x 0.1 mm Thickness when folded two times = 2 x 2 x 0.1 mm Thickness when folded three times = 2^3 x 0.1 mm .. … …. Thickness when folded 42 times = 2^42 x 0.1 mm 2^42 x 0.1 mm = 4,39,804 kilometres 4,39,804 kilometres is more than the distance between the earth and the moon which is 3,84,400 kilometres

_____
5 hat: 3w: 2b
3 random hats on A,B,C
A,B,C in a line where A can see B&C , B can C and C cannot see.
A could not say answer
B could not say
C said correct answer: How?
	https://youtu.be/-09T_F2Gm6Y
_____
100 floor eggs
https://www.youtube.com/watch?v=uBhSIKLlvdk&t=325s
  worst case: 100
  wrost case:  19 (divide a little,conquer a bit)
______

total squires in chess board: https://www.youtube.com/watch?v=KX7fDZQUtd0
2by2 = (2*2) + (1*1)
3by3 = (3*3) + (2*2) + (1*1)

nbyn = (n*n) + (n-1)^2 + (n-2)^3 + ..
chess board: 204
_________
1 bulb - 3 switches
ans:1 
https://www.youtube.com/watch?v=lNf6aZmgFeA
______
8 ball 1 heavier
find out which one is heavier using 2 uses of balancer.
____
10 boxes of balls each weight 10 grams. One box is defective with each weighing 9 grams.
find out the bad one with using weigh machine only once.
____
link chain of 5 with less
______
___
free lancer
  upwork/fiverr/freelancer/peopleperhour/angellist

