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

function getRandomNumber(maxValue)
	math.randomseed(os.time())
	math.random()
	return math.random(maxValue)
end

local number = getRandomNumber(100)    
print "guess number"

while answer ~= number do

	answer = io.read("*n")


	-- If loop
	if answer  < number then
	    print "low"
	elseif answer > number then
	    print "high"
	else 
	    print "correct"
	end
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

## Functions
* Functions in Lua are first class citizens, that means they are like any other type
* Functions can be passed, returned from other functions

## Variadic Functions (variable arguments)

``` lua
function findMax(...)
	local arguments = {...}		-- table
	local max = ...
	
	for i=1, #arguments do
	    if( arguments[i] > max ) then
	        max = arguments[i]
	    end
	end
	
	return max
end

function variadicFuncSample(...)
    msg1,msg2,msg3 = ...
    print("msg1: " )
    print(msg1)

    print("msg2: " )
    print(msg2)

    print("msg3: " )
    print(msg3)

end

variadicFuncSample("onlymsg1")
variadicFuncSample("111","2222")
variadicFuncSample("111","2222","3333333")

answer = findMax(3,5,7, 9)
print(answer)

``` 

## Using Function as Data

``` lua
function add(x, y)
   return x+y
end

function sub(x,y)
  return x-y
end

function calculate(x,y,f)
   return f(x,y)
end 

print "enter a number"
local x= io.read("*n","*l")		-- reading the line also so that it will be clear from input buffer
print "enter another number"
local y = io.read("*n","*l")
print "do you want to add or subtract ? (Type + or - )"
local op = io.read(1, "*l")

if op == '-' then
   operation = sub
else
   operation  = add
end

print( calculate(x,y, operation))

```
## Iterator

``` lua
function simpleCalculator(max)
	local count = 0	
	return function()
	   count = count+2		-- clouser ( using local variable )
	   if  count  > max then
	      return nil
	   end
	   
	   return count
	   
	end
end


for v in simpleCalculator(50) do
	print(v)
end

```

## Table ( like hashtable)

``` lua
local grades = {}

while true do
	print "enter student name (q to quit)"
	local name = io.read()
	
	if name == "q" then
		break
	end
	
	print "enter score"
	local score = io.read("*n","*l")
	grades[name] = score
end

print "pring grades"
for k,v in pairs(grades) do
	print(k,v)
end

local grades1 = {Mary = "100", Teacher = "150"}
print(grades1.Mary)
```

## Table as array
```lua
local items = {15,20,30}

for k,v in pairs(items) do
	print( k ,v)
end
```
