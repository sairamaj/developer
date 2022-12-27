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

