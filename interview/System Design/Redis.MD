* redis-cli
  * config get *
  * ping

## Data Types
### Strings
```cmd
    set name 'sairama'
    get name
```

### Hashes
Key value pair
```cmd
    hmset user1 name 'sai' last 'jamal'
    hgetall user1
```

### Lists
list of strings, sorted by insertion order. can add head or tail
```cmd
    lpush users user3
    lpush users user2
    lpush users user1
    rpush users user4

    lrange users 0 100
```

### Sets
order collection of strings. add,remove and test for existence of members in O(1)
```cmd
 sadd fruits banana
 sadd fruits apple
 sadd fruits apple

 smembers fruits   
```

### Sorted Sets
```cmd
zadd userscores 100 user1
zadd userscores 200 user2
zadd userscores 300 user0
zadd userscores 300 user2

zrangebyscore userscores 0  1000
```

[tutorial point](https://www.tutorialspoint.com/redis/index.htm)
_____


 ## HyperLogLog
* A HyperLogLog is a probabilistic data structure used to count unique values — or as it’s referred to in mathematics: calculating the cardinality of a set.
```cmd
   pfadd visitors alice bob carol
   pfcount visitors

   pfadd customers alice dan
   pfcount customers

   pfmerge everyone visitors customers
   pfcount everyone
   pfcount visitors customers
```

unique visitors
 [resource](https://thoughtbot.com/blog/hyperloglogs-in-redis)

## Publish Subscribe$
```cmd
subscribe redischat
publish resichat 'did you get this?'
```

## Transactions
* All commands in a transaction are sequentially executed as a single isolated operation. It is not possible that a request issued by another client is served in the middle of the execution of a Redis transaction.
* Redis transaction is also atomic. Atomic means either all of the commands or none are processed.
```cmd
    multi
    set tutorial redis
    get tutorial
    incr visitors
    exec
```

## Scripting
* Lua Interpreter.

______

## Use Cases
[resource](https://www.objectrocket.com/blog/how-to/top-5-redis-use-cases/)
* Session Caching
* Full Page Cache(FPC)
* Queues
* LeaderBoard/Counting
* Pub/Sub

_____

[resource-2](http://highscalability.com/blog/2011/7/6/11-common-web-use-cases-solved-in-redis.html)
* Show latest items listings in your home page
  * LPUSH used to insert a content id at the had of the list.
* Deletion and filtering
* Leaderboards and related problems.
* Order by user votes and time.
  * LPUSH + LTRIM 
* Implement expires on items
* Counting stuff
  * INCRBY command makes it easy to atomically keep counters; GETSET to atomically clear the counter
* Unique N items in a given amount of time
* Real time analysis of what is happening, for stats, anti spam, or whatever
* Pub/Sub
* Queues
* Caching
______

[resource-3](https://redis.com/redis-best-practices/indexing-patterns/geospatial/)
* Geospecial
```cmd
GEOADD cars -115.17087 36.12306 my-car
GEOADD cars -115.171971 36.120609 robins-car
GEODIST cars my-car robins-car
```
_____
## Redis Patterns
[patterns] (https://redis.com/redis-best-practices)
