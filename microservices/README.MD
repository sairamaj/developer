### Definitions
* Small , autonomous services that work together
* Loosely coupled service oriented architecture with bounded contexts.
* Developing a single application as a suite of small services, each running in its own process and communicating with lightweight mechanisms, often an HTTP resource API.
* These services are built around business capabilities and independently deployable by fully automated deployment machinery.
* There is a bare minimum of centralized management of these services, which maybe written in different programming languages and use different data storage technologies.

### Monolith
#### Pros
* Fewer Cross-cutting concerns
* Less Operational Overhead
* Easier Testing
* Performance

#### Cons
* Overly-tight coupling
* Harder to understand

### Microservices
#### Pros
* Better organization
* Decoupled
* Performance
* Fewer mistakes

#### Cons
* Cross-cutting concerns across each service
* Higher operational overhead

### Characteristics of well designed
* It does not share database tables with another service.
* It has a minimal amount of database tables.
* Its thoughtfully stateful or stateless
* Its data availability needs are accounted for
* Its a single source of truth


[Source](https://buttercms.com/books/microservices-for-startups/)

