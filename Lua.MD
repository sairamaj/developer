# Types
* nil
* boolean
* number
* string
* userdata
* function
* thread
* table

## ex
``` lua

math.randomseed(os.time())
math.random()
local number = math.random(100)     -- scoping

-- while loop
print "guess number:"
while answer ~= number do

	local answer = io.read("*n")

	if answer  < number then
	    print "low"
	elseif answer > number then
	    print "high"
	else 
	    print "correct"
	end

    print "guess again:"
end


print(number)

```

* "hi" .. "there"  (concatenation)
* #name  (length)

## Loops
* __While__ - __while__ boolean expression __do__ something __end__
* __Repeat__ - __repeat__ something __until__ boolean expression
* __For__(__Numeric__) - __for__ variable = start,end,step __do__ something __end__
* __For__(__Generic__) - __for__ k,v in iterator __do__ something __end__

* By default, all variables in Lua are globally scoped
