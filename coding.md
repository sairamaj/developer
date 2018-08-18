# During coding
* Style Cop
* Code analysis
* Code metrics

# Metrics

* Maintainability index
  * how hard is code to maintain
  * Higher is the better

* Cyclomatic Complexity
  * Structural complexity of code
  * Lower is better
  * How many paths are there through your code?
  * More paths -> harder to test
  * Harder to test -> harder to maintain

* Depth of inheritance
  * How deep is your inheritance hierarchy?

* Class coupling
  * Measure coupling vs Cohesion
  * Cohesion = good
  * Coupling = bad
  * Are there lots of dependencies that makes re-use difficult.

* Lines of code
   * Looks at IL

* ### 
  ## Code smells within classes.
  * Comments ( Are these necessary? Do they explain why and not what?) 
  * Long Methods  
  * Long parameter list
  * Duplicate code
  * Conditional complexity ( watch out large conditional logic blocks)
  * Large Class
  * Type embedded in name.
  * Un communicative name ( does the name of the method succinctly describe what the method does? Could you read the methods' name to another developer and have them explain to yo what it does?)
  * Dead code ( ruthlessly delete code that is n't being used. That's why we have source control systems.)
  * Speculative Generality ( write coe to solve today's problems, and worry about tomorrow's problems when they actually materialize.)
  * Oddball solution ( There should be only one way of solving the same problem in your code. If you find an oddball solution, it could be a case of poorly duplicated code.) 
  * Temporary field ( Watch out for objects that contain a l ot of optional or unnecessary fields. if you're passing an object as  a parameter to a method, make sure that you're using all of it and not cherry-picking single fields.)

## Code smells between classes.
  * Alternative classes with different interfaces ( if two classes are similar on the inside, but different on the outside, perhaps they can be modified to share a common interface.)
  * Primitive Obsession ( don't use a gaggle of primitive data type variables a a poor man's substitute for a class.)
  * Data Class ( Avoid classes that passively store data. may be domain models are exceptional to this)
  * Data Clumps (If you always see the same data hanging around together, may be it belongs together)
  * Refused Bequest ( if you inherit from a class, but never use any of the inherited functionality, should you really be using inheritance)
  * Inappropriate intimacy (watch out for classes that spend too much time together. classes should know as little as possible about each other.)
  * Indecent exposure ( beware of classes that unnecessarily expose their internals.)
  * Feature Envy
  * Lazy class 
  * Message Chains ( watch out for long sequences of method calls)
  * Middle man ( if a class delegating all its work, why does it exists?)
  * Divergent change ( if, overtime you make changes to a class that touch completely different parts of the class, it may contain too much unrelated functionality.)
  * Shotgun Surgery  ( If a change in one class required cascading changes in several related classes, consider refactoring so that the changes are limited to a single class.)
  * Parallel Inheritance Hierarchies  ( every time you make a subclass of one class, you must als make a subclass of another. )
  * Incomplete library class
  * Solution sprawl ( if it takes five classes to do anything useful, you might have solution sprawl)

  * [Code smells](https://blog.codinghorror.com/code-smells/)
* ### [Static methods are code smell](http://www.benday.com/blogfiles/StaticMethodsCodeSmell/BenDay_StaticMethods_CodeSmell.pdf)

## Some more code smells
* Duplicate code (copy and paste)

# [Code Metrics - Cyclomatic  Complexity](https://blogs.msdn.microsoft.com/zainnab/2011/05/17/code-metrics-cyclomatic-complexity/)