## Redis Sentinel 
*  Provides a simple and automatic high availability (HA) solution for Redis
*  [Introduction to Redis Sentinel](http://objectrocket.com/blog/how-to/introduction-to-redis-sentinel)
*  [Redis Sentinel Documentation](https://redis.io/topics/sentinel)


* Commands
    * _Keys_ *
    * _Type_ <keyname>
    * _Hgetall_ <keyname>

# Listing Hash with Lua
```lua
    local matches = redis.call('KEYS', 'keynamehere')
    for _,key in ipairs(matches) do
    local items = redis.call('HGETALL', key)
    return items
    
    end
```

