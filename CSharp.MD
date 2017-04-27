### null coalesce operator
*  ?? is used to simplify null expression as follows
 * possibilyNullVlaue ?? valueIfNull
 ```csharp
 string pageTitle = suppliedTitle ?? "Defalt Title";
 // which is equivalent
 string pageTitle = (suppliedTitle != null) ? suppliedTitle : "Default Title";
 // or
 string pageTitle;

 if (suppliedTitle != null)
    pageTitle = suppliedTitle;
 else
    pageTitle = "Default Title";

 ```

### The __ternary operator__ is an __operator__ that takes three arguments. The first argument is a comparison argument, the second is the result upon a true comparison, and the third is the result upon a false comparison. If it helps you can think of the operator as shortened way of writing an if-else statement.
* condition ? first_expression : second_expression; 

```csharp
int input = Convert.ToInt32(Console.ReadLine());  
string classify;  
  
// if-else construction.  
if (input > 0)  
    classify = "positive";  
else  
    classify = "negative";  
  
// ?: conditional operator.  
classify = (input > 0) ? "positive" : "negative";  
```


 