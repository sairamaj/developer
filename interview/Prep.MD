* Certified Azure Solution Architect : (Passed AZ 303 & AZ 304 recently)

### My work in recent years
* COASP Self Service Portal
  * Purpose
    * Enable every user to quickly bring up the COASP environments through self service portal.
  
  * Situation
    * Team is spending lot of admin work to spin up a application environment  test a feature as this process was involeved rasing service ticket and invovling another group in creating the base environment. 
  * Task
    * During this phase I had a work goal to learn Azure.
  * Action 
    * As we already got a subscription for dev to experiment with Azure by dev , I took this opporunity to make this entier process simple.
  * Result
    * Developed a Blazor backed up web portal where one can create the entire isolated environment (which has 3 serveers ) within 5mins. A developer can create this , test the functionality and tear down the environemnt through portal. Also extended Azure 'az' cli to automate this process. This involved terraform , Azure services, Pipelines to automate the entire build process.
    
_____

* TP Redis
  * Purpose
    * Make TP session stateless (Making user session reliable and protect from TP failures)
  * Situation
    * We have legacy C++ application which is the main server side transaction processor system. All the client systems communicate to this which is highly scalable, multi tenant and multi thread DCOM application. The problem with this application is it maintains user session and any crash or problem with this service will lost the user sessions.
  * Task
     * We have to make this legacy C++ service to state less service.
  * Action
     * Integrated Redis cache in this legacy C++ component. During this some optimiations has to be done to make smart updates to the redis cache. As C++ transaction code is touching the user session data , I need to make minimual changes  to not to disturb the code line but integrate this session data in to Redis. After going through the session data , found that data can be split and along with some meta data one can store in the Redis to make this state less with minimal impact and achieving the functionality. Need to update the custom client router component to detect the service down and redirect the traffic to different service which can bring the Redis cache in to life and execute the transaction.
  * Result
    * After working couple of months in this project , developing some integration tests to cover this legacy , we have production deployment where one can just kill the service but not loosing the sesion as client comopnent can detect and route to the new service on different server which can bring the Redis cache in to life and execute the user sessions.  
    
  * Challenges
    * Integrating Redis in to 20+  years of legacy of C++
    * The user session data is all over the place in C++ 
    * Optimize the data syncing (need to come up with some smart detection)
    * Need to come up with Redis connection pooling based on the session data
    * Updates on VLB router to take care of smart detection to redirect the user session to working TP in case of TP failures) 
    
______

* Host Integration Service
  * Purpose
    * Move from legacy C++ host server.exe (not scalable after 60 tenants)
  * Challenges
    * As Hostserver is framework and lot of code has been written as plug-in moving in to new C# WCF service and keeping the 100% compatible to this plug-in code is big challenge.
    * Has to come up with innovative way of Tenant level throttling
    * Has to use some inner working of IIS to take care of these.

______

* Architectural change in HIS to communicate to Core for parallel processing
  * Purpose
  * Operations from HIS to Core are synchronous and serial which make them slow when we have multiple calls needed to core to gather information. This is current G1CU issue.
  * Challenges
    * Whenever we introduce asynchronous and Parallel operations we need to take care of the following
    * Throttling ( Not to allow one Tenant to take complete resources)
    * Timeouts (In a set of operations some can succeed and some can timeout)
    * Queuing (we cannot spin threads to do parallel tasks) 

_____

* Circuit Breaker in COASP
  * Purpose
  * Introduce circuit breaker in COASP services when calling external clients to fail safely in case of issues with external entities
  * Challenges
    * Develop package such that it can be integrated easily with external services without much changes to existing code.

_______

* Voltage Integration
  * Purpose
    * Voltage encryption feature in COASP across all Edges
  * Challenges
    * Come up with framework level addons to integrate voltage instead of changing the entire code base to take care of this
    * Come up with tenant level, field level (configuration at account numbers, tax ids fields)
    * Use appropriate framework edges like WCF behaviors for WCF services, HTTP extensions for REST apis to integrate voltage.

______

* Config Service Redis Integration 
  *  Purpose
    * Integrate Redis in to COASP configuration system to get dynamic updates , eliminate background refreshes 
  * Situation
    * Another team in the company implemented Redis cache in to the product configuration and things worked in their dev but in performance lab , the web application which has this Redis cache integration was not working as expected (some times the app won't come up and some other time takes too long)  
  * Task
    * I have been tasked to look in to it. Along with team who are new to Redis, I was also new to Redis cache at that time.
  * Action
    * I went though Redis cache architecture, gone through Redis API and also gone through teams implementation in their web app. On the surface everything looked right. I went through the dev system where it is work ing fine and then Performance lab where it did not work. Found one big difference is the data and how these has been organized in to Redis Cache in the code. It turned out the team has come up with 4 big keys and each key containing a big json blob which has 150MB each. From the redis documentation found that Redis works great with more keys and less value data. But the team went too far with implementation and also in order to compatible with their legacy code , they said it will take long time to implement the new way. At this point I have no chice other than to see whether with any minimal change I can make this work. I have downloaded .NET implementation of redis by Stackexchange library and went through the code and debugged where the latency is. In the process I have to understand some socket programming and some multiplexing logic in this library. Ultimately found by tweking some inner working of this library we can make things faster. The latency is happening because of decryption of this large data. The default implementation is doing decypting the small chunks of 4K as the data is received causing the high CPU and hence latency. At this point implemented read buffer option in the library where enabled , the response chunks are collected and at the end one decryption is done. 
  * Result
     Out deployment is used this custom stack exchange and the web app was able to successful in loading. Over the peroid of time the data grew (because of clients as this app is multi tenant) and still the web app is workinas expected till today.

    * Category
    * Give me an example of a difficult problem you solved. How did you solve this problem
______
		
* Conditional Logging
  * Purpose
    * Enabling debug log levels on the fly for a given tenant to troubleshoot.
  * Challenges
    * Turn on debug for specific tenant without effecting performance hit in production. 
    * Need to manipulate log4net internals to come with solution to turn dynamic DEBUG for given tenant.
    * Auto On/Off feature for this tenant level DEBUG 

______

* HIS Framework
  * Purpose
    * Streamline the Core integration dev & test  & automation work
  * Challenges
    * Develop framework to abstract the integration layer between Voyager and Core
    * Inject New DI  & Interface approach to the existing code and standardize the HIS development.

_____

* RC4 Migration ( to AES )
  * Purpose
    * Move away legacy RC4 C++ code which has memory leak (Microsoft deprecated this library which has leak)
  * Challenge
    * Voyager platform has deeply integrated with legacy C++ code. Moving this code in to new managed AES encryption.
    * Come up with migration strategy is challenging as we have large amounts of encrypted data and cannot afford to do offline migration

____

* Façade Service
  * Purpose
    * Expose voyager DCOM layer as WCF service, so that clients can remove our VLB (custom component to communicate to Voyager) and use as first class service.
  * Challenge
    * As Voyager requests and responses were legacy ( done long back) and these types were not 100% compatible with WCF data types.
    * Has to extend low level WCF Schema generator to make it Voyager SDK types to work.
    * Generation of the dynamic services based on SDK request and response types posed some challenges 

____

* Response Caching
  * Purpose
    * Cache package for API GET responses which are static for most of the time (This is part of client perf test)
  *  Challenges
    * Incorporate these caching without modifying the existing code and come up with auto config changes (Turn on/off feature dynamically).
______

* Stand-in
  * Purpose
    * Divert the traffic to Stand-in server in case of Core down.
  * Challenge
    * TP (C++) code has been modified to incorporate.
    * Bringing min HIS layer in to TP (we will avoid HIS layer completely in case of transaction going to stand-in).
______

* Concurrent session feature
  * Purpose
    * Notifications to users whenever the user logins happening multiple times within same time.

  * Challenges
    * As we have to intercept login in event in TP C++ code and login event is the critical path, we need to come up with some smart strategies to add this feature.
    * The rules which to identify a concurrent session needs to be configurable as we have multiple clients and not all will participate in concurrent session feature.

_____

* Give me an example of a difficult problem you solved. How did you solve this problem?
  * Config Service Redis Integration

* Tell me about a mistake that you’ve made. How did you handle it?

* Can you tell me about a challenging situation you overcame at work?

* Tell me about a time you learned a new skill. How did you approach it and how to did you apply your new learnings?
  * COASP Azure Portal (Blazor and UI) 

* Has there been a time when you had to pitch an idea to a manager or senior leader? What was the outcome?
  * TP Redis.

* Tell me about a time when you overcame a conflict at work.
  

* Explain a situation in which you would have handled things differently.

* Tell me about a time you handled a stressful situation when you were under a lot of pressure.
  * A major Client Performance issue

* Can you tell me about a time you set and achieved a certain goal?

* What is your proudest professional accomplishment and why?
_____