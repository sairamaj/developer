A __pattern__ is a "reusable solution to a problem that occurs in particular context". This is already a major improvement because it introduces the idea of a context

A commonly used pattern structure includes three especially valuable sections:forces, resulting context, and related patterns.

## forces
    The forces section describes the issues that you must address when solving a problem in a given context. Forces can conflict so it might not be possible to solve all them. Which
forces are more important depends on the context. You have to prioritize solving some forces over others. For example, code must be easy to understand and have good performance. Code written in a reactive style has better performance than synchronous code, yet is often more difficult to understand. Explicitly listing the forces is useful
because it makes it clear what issues need to be solved. 

## RESULTING CONTEXT
The resulting context section describes the consequences of applying the pattern. It consists of three parts:
* benefits - the benefits of the pattern including the forces that have been resolved
* drawbacks - the drawbacks of the pattern including the unresolved forces
* issues - the new problems that have been introduced by applying the pattern.

## RELATED PATTERNS
 The related patterns section describes the relationship between this pattern and other patterns. There are three types of relationships between patterns

* Predecessor - a predecessor pattern is a pattern that motivates the need for this pattern. For example, the Microservice Architecture pattern is the predecessor to the rest of the
patterns in the pattern language except the monolithic architecture pattern.

* Successor - a pattern that solves an issue that is introduced by this pattern. For example, if you apply the Microservice Architecture pattern you must then apply numerous successor patterns including service discovery patterns and the Circuit Breaker pattern.

* Alternative - a pattern that provides an alternative solution to this pattern. For example,the Monolithic Architecture pattern and the Microservice Architecture pattern are
alternative ways of architecting an application. You pick one or the other

[Source](https://manning-content.s3.amazonaws.com/download/b/0e605ff-febf-4839-8398-e41ecce7d3a2/Richardson3_MP_MEAP_V02_ch1.pdf)


