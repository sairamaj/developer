* [Navigating the 8 fallacies of distributed computing](https://ably.com/blog/8-fallacies-of-distributed-computing)
  * The network is reliable.
    * automatic reconnection
    * retries
    * dedupication. 
      * deduplication is a technique for eliminating duplicate copies of repeating data. It can improve storage utilization and reduce the overall amount of storage media required to meet storage capacity needs
    * (idempotency).
      * An idempotent operation is one that has the same effect whether it is performed once or many times.
  * Latency is zero.
    * Caching
    * Event driven protocol
    * Server performance
    * Edge computing (bring data closer to user in cloud environment)
  * Bandwidth is infinite.
    * Comprehensive monitoring.
    * Multiplexing.
    * Light weight data formats.
    * Network traffic control.
      * throttling/rate limiting
      * congestion control
      * exponential backoff.
  * The network is secure.
    * Threat modelling.
    * Defense in depth.
    * Security mindset.
  * Topology doesn't change.
  * There is one administrator.
  * Transport cost is zero.
  * The network is homogeneous.
* [Engineering a fault tolerant distributed system](https://ably.com/blog/engineering-dependability-and-fault-tolerance-in-a-distributed-system)
  * _Dependability_ is a measure of both the availability and reliability of a service.
  * _Availability_ is when a product or service is available for use when required.
  * _Reliability_ is whether a product or service works as expected.

If availability is the assurance of uptime, reliability preserves quality of that uptime in terms of functionality and user experience.
