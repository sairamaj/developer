[resource](https://www.espn.com/nfl/game?gameId=401326631)

* Constraints
  * Uniform interface
    * The uniform interface constraint defines the interface between clients and servers. It simplifies and decouples the architecture, which enables each part to evolve independently. The four guiding principles of the uniform interface are
  * Stateless
  * Cacheable
  * Client-Server
  * Layered System

* Producing a great API is 80% art and 20% science
* Design [resource](https://www.restapitutorial.com/lessons/restquicktips.html)
  * Use identifiers in your URLs instead of in the query-string. Using URL query-string parameters is fantastic for filtering, but not for resource names
  * Leverage the hierarchical nature of the URL to imply structure.
  * Design for your clients, not for your data.
  * Resource names should be nouns. Avoid verbs as resource names, to improve clarity. Use the HTTP methods to specify the verb portion of the request.
  * Use plurals in URL segments to keep your API URIs consistent across all HTTP methods, using the collection metaphor.
    * Recommended: /customers/33245/orders/8769/lineitems/1
    * Not: /customer/33245/order/8769/lineitem/1
  * Use lower-case in URL segments, separating words with underscores ('_') or hyphens ('-'). Some servers ignore case so it's best to be clear.
  * Keep URLs as short as possible, with as few segments as makes sense.

## Status Codes [resource](https://www.restapitutorial.com/lessons/restquicktips.html)
* 200 OK
  * General success status code. This is the most common code. Used to indicate success.
* 201 CREATED
  * Successful creation occurred (via either POST or PUT). Set the Location header to contain a link to the newly-created resource (on POST). Response body content may or may not be present.
* 204 NO CONTENT
  * Indicates success but nothing is in the response body, often used for DELETE and PUT operations.
* 400 BAD REQUEST
  * General error for when fulfilling the request would cause an invalid state. Domain validation errors, missing data, etc. are some examples.
* 401 UNAUTHORIZED
  * Error code response for missing or invalid authentication token.
* 403 FORBIDDEN
  * Error code for when the user is not authorized to perform the operation or the resource is unavailable for some reason (e.g. time constraints, etc.).
* 404 NOT FOUND
  * Used when the requested resource is not found, whether it doesn't exist or if there was a 401 or 403 that, for security reasons, the service wants to mask.
* 405 METHOD NOT ALLOWED
  * Used to indicate that the requested URL exists, but the requested HTTP method is not applicable. For example, POST /users/12345 where the API doesn't support creation of resources this way (with a provided ID). The Allow HTTP header must be set when returning a 405 to indicate the HTTP methods that are supported. In the previous case, the header would look like "Allow: GET, PUT, DELETE"
* 409 CONFLICT
  * Whenever a resource conflict would be caused by fulfilling the request. Duplicate entries, such as trying to create two customers with the same information, and deleting root objects when cascade-delete is not supported are a couple of examples.
* 500 INTERNAL SERVER ERROR
  * Never return this intentionally. The general catch-all error when the server-side throws an exception. Use this only for errors that the consumer cannot address from their end.

## Consider Connectedness
One of the principles of REST is connectedness—via hypermedia links (search HATEOAS). While services are still useful without them, APIs become more self-descriptive and discoverable when links are returned in the response. At the very least, a 'self' link reference informs clients how the data was or can be retrieved. Additionally, utilize the HTTP Location header to contain a link on resource creation via POST (or PUT). For collections returned in a response that support pagination, 'first', 'last', 'next' and 'prev' links at a minimum are very helpful.

