Microservices architecture as a service-oriented architecture composed of loosely coupled elements that have bounded contexts.each service has a
focussed, cohesive set of responsibilities.The microservice architecture uses services as the unit of modularity.One way this loose coupling is achieved is by each service having it’s own datastore. 


## Benefits
* The code is easier for a developer to understand
* The small code base doesn’t slow down the IDE making developers more productive
* each service typically starts a lot faster than a large monolith, which again makes developers more productive, and speeds up deployments
* each service can be deployed independently of other services
* microservice architecture makes continuous deployment feasible
* each service can be scaled independently of other services
* easier to scale development
* improves fault isolation
* eliminates any long-term commitment to a technology stack
* because the services are small, it becomes practical to rewrite them using better languages and technologies. It also means that if the trial of a new technology fails you can throw away that work without risking the entire project. 

## Drawbacks
* using the microservice architecture is that there isn’t a concrete, well-defined algorithm for decomposing a system into services. Like much of software development, it is some what of an art. To make matter’s worse, if you decompose a system incorrectly you will build a distributed monolith, a system consisting of coupled services that must be deployed together. It has the drawbacks of both the monolithic architecture and the microservice architecture
* developers must deal with the additional complexity of creating a distributed system
* introduces significant operational complexity

