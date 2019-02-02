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

### Generating links using route names in asp.net web api
```csharp
    [Route("{id:int}", Name ="GetStudentyById")]
    public Student Get(int id){

    }

    public HttpResponseMessage Post(Student student){
        var response = Request.CreateResponse(HttpStatusCode.Created);  // status code: 201 
        response.Headers.Location = new Url( Url.Link("GetStudentyById", new { id = student id}));
        return response;
    }
```

[source](https://www.youtube.com/watch?v=sqOw6E11AAM)

[anotherone](https://odetocode.com/blogs/scott/archive/2013/03/27/webapi-tip-5-generating-links.aspx)

[error handling](https://blog.restcase.com/rest-api-error-codes-101/)

[filtering,sorting,pagination](https://www.moesif.com/blog/technical/api-design/REST-API-Design-Filtering-Sorting-and-Pagination/)

[API design guidelines](https://hackernoon.com/restful-api-designing-guidelines-the-best-practices-60e1d954e7c9)

