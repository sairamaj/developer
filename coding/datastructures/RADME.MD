* Physical data structures
  * Arrays
  * Linked list 
* Logical
  * Stack (Linear)
  * Queue (Linear)
  * Trees (non linear)
  * Graphs(non linear)
  * Hashtable (tabular)

* Abstract Data Type
  * Representation of Data
  * Operations on data.

* Recursion
  * Tail recursion
    * Can be converted in to loop by compiler optimization.
  * Head recursion
    * First thing in the func
  * Linear Recursion
    * One time
  * Tree Recursion
    * More than one time.
  * Indirect Recursion
    * Circullar (A->B->A)
  * Nested recursion
    * Func call with parameter as function call
  ```cmd
  Use tree for function calling
  For statck (activation record) use vertical box 
  |     |
  |     |
  |_____|
  ``` 

* Problem of sum of natural numbers
```cplus
// recursion
int sum(int n){
    if(n == 0){
        return 0;
    }
    return n+sum(n-1);
}
```
```cplus
// iteration
int sumIterative(int n){
    int sum = 0;

    while(n >0){
        sum += n;
        n--;
    }

    return sum;
}
```

```cplus
// formula
int sumFormula(int n){
    return ((n)*(n+1))/2;
}
```

* Exponent
```cplus
int exp(int n, int m)
{
    if (m == 1)
    {
        return n;
    }

    return n * exp(n, m - 1);
}
```
```cplus
// (2^8)=>(2^4)*2 concept.
int expoptimization(int n, int m)
{
    if (m == 0)
    {
        return 1;
    }
    int val = exp(n, (m) / 2);
    int final = val * val;
    if(m%2 == 1){
        return final*n;
    }
    return final;
}
```

* taylor series ( revisit)

* Sorting
  * Number of comparisions
  * Number of swaps
  * Adaptive
  * Stable
    * Order will not change.
  * Extra memory
  * Comparision Sorts
     * O(n^2)
       * Bubble
         * Used for finding out k top elements. (just do k passes.)
         ```cmd
          for(int i=0; i<n-1; i++){
            for(j=0; j<n-1-i; j++>){  // note: j<n-1-i
              if( a[j] < a[j+1] )
              {
                swap(&a[j],&a[j+1])
                isswapdone = true;
              }
            }
            if(!isswapdone){
              break;    // no need to do further as all are sorted ( adaptive)
            }
          }
         ```
       * Insertion
          * Idea of inserting an element in existin sorted list.
          * Take 1 element which is sorted by default and start insert new element.
          * Designed for linked list.
       * Selection
           * Select position.
           * k passes gives k sorted elements.
       * QuickSort
           * element is in sorted if all the elements to left are less and all the elements are right or more.
    * O(nlogn)
       * Heap 
       * Merge
       * Quick
       * Tree
    * O(n^3/2)
       * Shell
  * Index based sorts (takes extra space)
      * O(n)
        * Count
        * Bucket/Bin
        * Radix

    