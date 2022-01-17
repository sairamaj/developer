Dynamic programming is a powerful tool because it can break a complex problem into manageable subproblems, avoid unnecessary recalculation of overlapping subproblems, and use the results of those subproblems to solve the initial complex problem. DP not only aids us in solving complex problems, but it also greatly improves the time complexity compared to brute force solutions. For example, the brute force solution for calculating the Fibonacci sequence has exponential time complexity, while the dynamic programming solution will have linear time complexity
  * Bottom Up
  * Top-down (recursion)(memoization)

[DP for beginners](https://www.youtube.com/watch?v=jTjRGe0wRvI&list=PLVrpF4r7WIhTT1hJqZmjP10nxsmrbRvlf)

* Solving exponential O(2^n) to Polynomical O(n^2) and may be sometimes to linear.
* 2 types
  * Combinatoric
    * How many?
    * __How many__ ways to make change?
    * __How many__ ways to traverse graph?
    * __How many__ steps needed to get from Point A to Point B?
  * Optimization
    * What is the minimum
    * What is the __minimum__ number of steps from Point A to PointB?
    * What is the __maximum__ profit gained by buying or selling a stock?
    * What is the __minimum__ cost to travel from New York to Mumbai?

__memoizing__ a result means to store the result of a function call, usually in a hashmap or an array, so that when the same function call is made again, we can simply return the memoized result instead of recalculating the result.


## Greedy Algorithm
* A global (overall) can be reached by choosing the optimal solution at each step
* A problem has an optimal substructure if the optimal solution to the entire problem contains the optimal solution to the sub-problems
* Problems that allow us to reuse previous solutions to smaller problems in order to calculate a solution to the current problem
* [youtube](https://www.youtube.com/watch?v=lfQvPHGtu6Q)


## Knapsack problem
* The knapsack problem is a problem in combinatorial optimization
* given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible
  * [definition](https://en.wikipedia.org/wiki/Knapsack_problem)
  * [youtube](https://www.youtube.com/watch?v=nLmhmB6NzcM)
  * [solution](https://medium.com/@fabianterh/
  how-to-solve-the-knapsack-problem-with-dynamic-programming-eb88c706d3cf)
* 0-1 knapsack
  * In this type of knapsack problem, there is only one item of each kind (or we can pick only one). So, we are available with only two options for each item, either pick it (1) or leave it (0)
* Details
```cmd
  Profit = {1,2,5,6}
  Weight = {2,3,4,5}
``