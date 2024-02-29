* security pages status 404 instead of forbidden (403)
* 303 for duplicate resources(???)
* [Microsoft standard](https://learn.microsoft.com/en-us/azure/architecture/best-practices/api-design)
* Swagger hub for design
* Domain driven design
  * Bounded context, domain, model
* [openapi spec](https://github.com/OAI/OpenAPI-Specification/tree/main/versions)
* Adding optional field which has PUT resource is a break changing as PUT may overwrite this optional field if the client does not supply.
* URL format
  * https://<baseurl>/<party>/<domain>/v<version-number>/<resource>
  * https://api-example.com/consumer/payments/v1/user
* Resource Processes (where some processing may happen at backend. can have simple verb to represent, like /enable/disable)
* The HEAD and OPTIONS methods allow resources to be inspected without retrieving a representation: neither method returns an entity body, just metadata in the form of HTTP headers.
  * [info](https://web.archive.org/web/20160528151316/https://www.safaribooksonline.com/blog/2013/05/29/tip-probe-web-resources-head-options-rest/)
  * HEAD can be used for optimization
  * Testing whether resource exists or not.
* [Http tunnelling](https://fanoframework.github.io/security/http-verb-tunnelling/)
* [Http status codes](https://en.wikipedia.org/wiki/List_of_HTTP_status_codes)
* Error format
  * type, detail, instance [info](https://datatracker.ietf.org/doc/html/rfc7807#page-15)
* PCI,HIPPA, PII
* [OWASP](https://github.com/OWASP/www-project-zap)
* Indirect id with tokenization
* [Health checks](https://datatracker.ietf.org/doc/html/draft-inadarei-api-health-check-04)
* [OData query](https://www.odata.org/getting-started/basic-tutorial/)
* [OData paging](https://learn.microsoft.com/en-us/odata/client/pagination)
  * [more](https://docs.oasis-open.org/odata/odata/v4.01/os/part1-protocol/odata-v4.01-os-part1-protocol.html)
* [OData Sorting](https://docs.oasis-open.org/odata/odata/v4.01/os/part1-protocol/odata-v4.01-os-part1-protocol.html#sec_SystemQueryOptionorderby)
* [$select](https://docs.oasis-open.org/odata/odata/v4.01/os/part1-protocol/odata-v4.01-os-part1-protocol.html#sec_SystemQueryOptionselect)
* [async pattern](https://learn.microsoft.com/en-us/azure/architecture/patterns/async-request-reply)
  * client pooling
  * [long polling with connection open and server sending message](https://javascript.info/long-polling)
  * [web hooks](https://zapier.com/blog/what-are-webhooks/)
* [Accept-Language](https://en.wikipedia.org/wiki/List_of_HTTP_header_fields)
* [Cacheable](https://restfulapi.net/rest-architectural-constraints/#cacheable)
  * Expires
  * Cache-Control
  * Last-Modified
  * ETag