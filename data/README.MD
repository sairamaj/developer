### Sql server pagination
* [Using Temp tables](https://web.archive.org/web/20211029044104/https://www.4guysfromrolla.com/webtech/062899-1.shtml)
  * Generate increment id column
  * Good for static tables
* [Improved version of above technique](https://web.archive.org/web/20211020131201/https://www.4guysfromrolla.com/webtech/042606-1.shtml)
  * SET options alter the current sessions handling of specific behavior; SET ROWCOUNT tells SQL Server to stop processing query results after it has processed the specified number of rows.
  
* Using OFFSET and FETCH
* Using SEEK method
* [Multiple methods](https://www.codeproject.com/Articles/6936/Paging-of-Large-Resultsets-in-ASP-NET)
* [OFFSET vs CURSOR approach](https://dev.to/appwrite/this-is-why-you-should-use-cursor-pagination-4nh5)
________

* OLTP
  * Online Transaction Processing
* OLAP
  * Online Analytical Processing

_____
[sql vs dynamodb](https://www.alexdebrie.com/posts/dynamodb-no-bad-queries/)
* Why SQL wont scale
  * SQL Joins (bad complexity)
    * NO SQL Plan for data (access pattern)
    * Pre join
    * No longer flexibility which was SQL giving
    * Duplicate the data
  ____

  * Difficult to scale horizontally
    * Partition key
  _____
  * Relational queries are unbounded
    * Limits on Query and Scans
  ______
  * DynamoDB does not have support for any aggregation operations, such as max, min, avg, or sum. My guess is that it's due to this 1MB
  _____
  * [database consistency](https://www.alexdebrie.com/posts/database-consistency/)
    * The CAP Theorem is fundamentally about replication, specifically network failures during replication.
    * Whereas the CAP Theorem is a distributed systems concept concerning replication, ACID is purely a database con
_____
* PACELC 
  * In the event of **P**artition, do I choose **A**vability or **C**onsisiteny?
  * **E**else do I optimize **L**atency or **C**onsistency?
_____
* A partition key design that doesn't distribute I/O requests effectively can create "hot" partitions that result in throttling and use your provisioned I/O capacity inefficiently.
____
* Availability
  * every request received by a non-failing node in the system must result in a response
  * [info](https://brooker.co.za/blog/2018/02/25/availability-liveness.html)