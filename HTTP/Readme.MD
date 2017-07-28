|      verb             |             description
|-----------------------| ------------------------
|      GET              |  is usually intended to retrieve some data, and is expected to be idempotent 
|                       |  (repeating the query does not have any side-effects) and can only send limited amounts of parameter data to the 
|                       |  server 
|      POST             |  request method requests that a web server accept the data enclosed in the body of the request message, most likely  
|                       |  for storing it. It is often used when uploading a file or when submitting a completed web form.
|      DELETE           |  Deletes the specified resource
|      HEAD             |  Same as GET but returns only HTTP headers and no document body
|      PATCH            |  Apply partial modifications to a resource.
|      PUT              |  Uploads a representation of the specified URI
|      OPTIONS          |  Returns the HTTP methods that the server supports
|      TRACE            |  Message loop-back test along the path to the target resource.
|                       |  TRACE allows the client to see what is being received at the other end of the request chain and use that data 
|                       |  for testing or diagnostic information. The value of the Via header field (section 14.45) is of particular interest, 
|                       |  since it acts as a trace of the request chain. Use of the Max-Forwards header field allows the client to limit the 
|                       |  length of the request chain, which is useful for testing a chain of proxies forwarding messages in an infinite loop
