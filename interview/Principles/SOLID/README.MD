# **S**O**L**I**D**

### Single Responsibility
A Class should have only one responsibility. It should have only one reason to change
* Testing
* Lower coupling
* Organization

### Open for execution, Closed for Modification
Classes should be open for extension, but closed for modification.In doing so, we stop ourselves from modifying existing code and causing potential bugs

### Liskov Substituion
Subclasses should be substitutable for their base classes.

This means that, given that class B is a subclass of class A, we should be able to pass an object of class B to any method that expects an object of class A and the method should not give any weird output in that case

### Interface Segragation
Larger interfaces should be split into smaller ones.By doing so, we can ensure that implementing classes only need to be constructed about methods that are of interest to them.

### Dependency Injection
The principles of dependency injection refers to the decoupling of software modules. This way instead of high level modules depending on low level modules, both will depend on abstractions.

### Resources
[freecodecamp](https://www.freecodecamp.org/news/solid-principles-explained-in-plain-english/)

[c#](https://www.c-sharpcorner.com/UploadFile/damubetha/solid-principles-in-C-Sharp/)

[blog](https://www.baeldung.com/solid-principles)

