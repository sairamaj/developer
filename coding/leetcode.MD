### Array tips
* Check whether input array can be modified which can save space.

### C++
```C++
    // int to string
    auto s = std::to_string(10);

    // std string to char*
    char *s = s.c_str();

    // array initiliazation
    int array[3] = {1,2,3}; 
```

### Generic Tips
* When something is halved at every step, it has a O(log, n) time complexity.
* Two pointer approach
  * Two pointers starts at different position: one starts at the beginning while another starts at the end;
  * Two pointers are moved at different speed: one is faster while another one might be slower.
* Careful with ++ and -- with precedences and assignments
* Careful with expressions and use parenthesis for proper evaluation.
* See whether dictionary can be used to minimize multiple passes in array (like storing already visited items)
* In-place Array operations help to reduce space complexity
* Think of moving backwards for arrays for smart operations.
* Slow pointer, Fast  Pointer approach
* Take all test cases including extremes (ex: empty array )

### Links
[Solving Techniques](https://javahungry.blogspot.com/2014/06/algorithm-problem-solving-techniques-or-approaches-for-software-programmer.html)


### Notes
* Brute force

* Interview tip for bit manipulation problems: if you don't know how to start, start from computing XOR for your input data. Strangely, that helps out for quite a lot of problems, Single Number II, Single Number III, Maximum XOR of Two Numbers in an Array, Repeated DNA Sequences, Maximum Product of Word Lengths, 