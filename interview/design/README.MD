* DRY
* KISS
* YAGNI
* SOLID
* Separation of Concern

[Layered architecture](https://github.com/aspnetrun/run-aspnetcore-basics)
[Layered architecture](https://github1.com/aspnetrun/run-aspnetcore-basics)

[Clean architecture](https://github.com/aspnetrun/run-aspnetcore-realworld)
[Clean architecture](https://github1.com/aspnetrun/run-aspnetcore-realworld)

* Strong Consistency is Mandatory && Independent Scale and Deploy is not required = MOdular Monolithic
* Strong Consistency is not Mandatory, Eventual Consistency is OK && Indepdnet Scale and Deploy is Required = Microservices

[Modular Monolithic with DDD](https://github.com/kgrzybek/modular-monolithic-with-ddd)
[Modular Monolithic with DDD](https://github1s.com/kgrzybek/modular-monolithic-with-ddd)

[Martin Fowler](https://martinfowler.com/articles/microservices.html)

* Microservices
  * Decomposition
  * Communication
  * Data Management
  * Transaction Management
  * Deployments
  * Resilience

![design](./design.png)

* Microservices Decompostion Patterns
![design](./micro_decomposition.png)
![scaling](./scaling.png)

  * By Business Capability
  * By Sub domain
  * Bounded context pattern
    * ![context](./bounedcontext.png)
    * Bounded context is the logical boundary that represents the smaller problem particles of the complex domain that are self consistent and as independent as possible.
    * Identity bounded context boundaries
![decomposition](./decomposition1.png)
![decomposition](./decomposition2.png)
![decomposition](./decomposition3.png)
![decomposition](./decomposition4.png)
![decomposition](./decomposition5.png)
![decomposition](./decomposition6.png)
![decomposition](./checklist.png)
![decomposition](./IdentityBoundedContext.png)

* Smart endpoints and dump pipes: microservices loosely coupling and expose endpoints with RESTFul APIs in order to provide end-end-end use cases.