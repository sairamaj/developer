## Key requirements for the API
* use web standards where they make sense
* should be friendly to developers and explorable via browser address bar
* simple, intuitive, consistent to make adoption not only easy but pleasant
* should be efficient, while maintaining balance with other requirements

### Resource
* should be noun
* your internal models may map neatly to resources, it isn't necessarily a one-to-one mapping. 
* not to leak irrelevant implementation details out to AIs

### End points
* endpoint name should be plural. (users, tickets, messages)

Define resource and actions apply to those resources

### Relationships
* If relationship exists independent of resource, include an identifier for it within the output of the resource (API consumer have to hit the relationship endpoint)
* If the relationship is commonly required alongside the resource, the API could offer functionality to automatically embed the relation's representation and avoid second hit to API.

### Actions that don't fit in to world of CRUD operations
[Source](http://www.vinaysahni.com/best-practices-for-a-pragmatic-restful-api)
