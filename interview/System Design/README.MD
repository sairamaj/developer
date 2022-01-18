## CAP theorem
This states that it is not possible for a distributed computer system to simultaneously provide all three of the following guarantees:

__Consistency__ (all nodes see the same data even at the same time with concurrent updates )

__Availability__ (a guarantee that every request receives a response about whether it was successful or failed)

__Partition tolerance__ (the system continues to operate despite arbitrary message loss or failure of part of the system)

____

## Scalability

Scalability is the ability of a system, network, or process to handle a growing amount of load by adding more resources. The adding of resource can be done in two ways

* Scale Up
* Scale Out

____

## Reliability
* is a probability of product will perform successfully under specified operating conditions for a given peroid of time.
* [resource](https://www.youtube.com/watch?v=BQXnKpP2lrI)
* Quality over time.
  * Failure Rate
  * Mean Time to failures(MTTF) - reliability index for __non-repairable__ (ex: light blub) units represents mean time to failure
  * Mean Time Between failures(MTBF) - reliability index for __repairable__ units represents mean time to failure

____

## ACID Properties
* __Atomicity__: It ensures all-or-none rule for database modifications.
* __Consistency__: Data values are consistent across the database.
* __Isolation__: Two transactions are said to be independent of one another.
* __Durability__: Data is not lost even at the time of server failure

____

## Optimistic locking

Optimistic Locking is a strategy where you read a record, take note of a version number (other methods to do this involve dates, timestamps or checksums/hashes) and check that the version hasn't changed before you write the record back. When you write the record back you filter the update on the version to make sure it's atomic. (i.e. hasn't been updated between when you check the version and write the record to the disk) and update the version in one hit.

If the record is dirty (i.e. different version to yours) you abort the transaction and the user can re-start it.

This strategy is most applicable to high-volume systems and three-tier architectures where you do not necessarily maintain a connection to the database for your session. In this situation the client cannot actually maintain database locks as the connections are taken from a pool and you may not be using the same connection from one access to the next.

## Pessimistic Lock
Pessimistic locking is when you take an exclusive lock so that no one else can start modifying the record

____

## Resources
[system design questions](https://www.fullstack.cafe/blog/system-design-interview-questions)
