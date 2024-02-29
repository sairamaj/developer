### Load Balancer vs GateWay

In general, a load balancer is used to distribute traffic between multiple servers, while an API gateway is used to provide a secure and consistent access layer for client applications 1.

Here are some scenarios where you might use one over the other:

* Use a load balancer when you need to:
  * Distribute traffic between multiple servers.
  * Ensure high availability of your application.
  * Scale your application horizontally.
  * Optimize resource utilization.
  * Improve performance and reduce latency.
  * Will work on Layer 4 & 7 of OSI (Transport & Application)

* Use an API gateway when you need to:
  * Provide a secure and consistent access layer for client applications.
  * Manage access to your backend services.
  * Authenticate and authorize incoming requests.
  * Enforce security policies.
  * Monitor and log incoming requests.
  * Will work on Layer 7 of OSI (Application)
  
In general, if you need to manage access to your backend services and enforce security policies, an API gateway is the better choice. If you need to distribute traffic between multiple servers and ensure high availability of your application, a load balancer is the better choice.

____

* __Anycast__ is a network addressing and routing methodology in which a single IP address is shared by devices (generally servers) in multiple locations. Routers direct packets addressed to this destination to the location nearest the sender, using their normal decision-making algorithms, typically the lowest number of BGP network hops. Anycast routing is widely used by content delivery networks such as web and name servers, to bring their content closer to end users [delivary schemes](https://en.wikipedia.org/wiki/Routing#Delivery_schemes)
  
____
