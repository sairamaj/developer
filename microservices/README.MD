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

____

* Event Driven systems
  * __Event Collaboration__ pattern, where events describe an evolving business process—like processing an online purchase or booking and settling a trade—and several services collaborate to push that work‐flow forward.
  * __Event Sourcing__ is just the observation that events (i.e., state
changes) are a core element of any system. So, if they are stored, immutably, in
the order they were created in, the resulting event log provides a comprehensive
audit of exactly what the system did. What’s more, we can always rederive the
current state of the system by rewinding the log and replaying the events in
order.Event Sourcing records our state changes, which ensures we know exactly what happened during our system’s execution, and we can always regenerate our current state
  * __CQRS__ is a natural progression from this. As a simple example, you might write
events to Kafka (write model), read them back, and then push them into a data‐
base (read model).
  * __Command Sourcing__ is essentially a variant of Event Sourcing but applied to
events that come into a service, rather than via the events it creates.So Command Sourcing lets us record our inputs, which means the system can
always be rewound and replayed.
