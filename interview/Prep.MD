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
  * Situation
    * Platform has legcy C++ application which communicates the core. This application is being launched by another service which configured for each tenant and its number of application instances. Because of windows limiations for the number of procesesing running and tenants being increased because of new clients, this application hosting is started showing the scalability and memory issues. In order to work with this and also move to managed C# code as service , the application needs to be rewritten to address some of these issues.As this is just framework and clients enhance this with plug-ins through COM objects and cannot affod to break any existing plug-ins as there are multiple plug-ins by different clients. 
  * Task
    * Design new application hosting in .NET managed service and be 100% compatible with existing plug-ins. As this is multi tenant application, the new service should be written such that tenant thottling so that no tenant can take over the system.
  * Action
    * Written a .NET managed WCF service to port C++ component. Able to finish the service before the big clients were brought in and also developed tenant throttling using WCF and IIS internals instead of developing custom code. Able to achieve 100% compatible with existing code and Migrated 200 clients from legacy multi application instance to single WCF service in phased approach over the period of time with zero downtime. 
  * Result
    * A WCF Single multi tenant with 100% backward plug-in compatible with tenant thorttling and application insights with windows performance counters.

  * Challenges
    * As Hostserver is framework and lot of code has been written as plug-in moving in to new C# WCF service and keeping the 100% compatible to this plug-in code is big challenge.
    * Has to come up with innovative way of Tenant level throttling
    * Has to use some inner working of IIS to take care of these.

______

* Architectural change in HIS to communicate to Core for parallel processing
  * Purpose
  * Situation
    * A big client after migrating to the Platform observed significant latencies in users online sessions. After going through different layers of the application one issue was found that this client access to backend core has multiple calls to backend in order to gather user accounts information. Because of the serieal nature of this and based on the user profile some of these needed lot of calls and this was causing significant latency. The product had never framework to make these calls in parallel and asynchronous. This was high severity issue and also the legacy product does not have any framework and needed to be come up quick solution to make these calls async and parallel without effecting other tenant calls.
  * Task
    * Develop a framework for async, parallel calls with tenant thorttling and batch operations with timeouts incorporated.
  * Action
    * Used .NET TPL framework and simple memory queue architecture developed a framework where client plug-in can call to queue the batch operations and gather the responses.
  * Result
    * By incorporating batch operaitons client calls along with async and parallel, significant portion of the latency has been solved for the client making client happy.
       
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
  * Situation
    * There were number of production outages because of 3rd party services were not responding properly during the peak production times. The consuming services in our product does not have any mechanisim to protect from this , causing the latency and system down issues.
  * Task
    * I have to come up with a strategy to protect our systems from 3rd party failures across all our consuming applications. The changes should be such that we will have different configurations for different services and the code changes should be minimal in order to reduce the testing area.
  * Action
    * Developed a internal package which consumes the standard .NET Polly package which has different Circuit breaker functionality. This module contains all the necessary configuraiton, application insights using performance counters and with Autofac DI was able inject this framework in to consuming application with minimal changes.
  * Result
    * Today we have all 3rd party calls go through this circuit breaker package and recover from any latency or failures from external systems. We never had this issue anytime after these changes in our production.

  * Challenges
    * Develop package such that it can be integrated easily with external services without much changes to existing code.

_______

* Voltage Integration
  * Purpose
    * Voltage encryption feature in COASP across all Edges
  * Situation
    * There is enterprise level effort to implement standard encryption for data. This is to integrate with 3rd party Voltage for sensitive fields across the enterprise. We need to add this functionality across entire suite of products. This effort is to take care of all edges and once data enters in to the system should encrypt the data and traver within the layers as encrypted data.
  * Task
    * Identified all the edges and use appropriate framework extensions (like WCF  Behavios for WCF services, HTTP extensions for REST API, Custom framework extension for custom applications) to integrate this tokenization/detokenization for sensitive fields. Migration has been idenfied as big tasks as the current system is multitenant and huge data exists in the system which needs to be encrypted without taking the system down. There were number of batch job applications which were either consuming external data or producing the data to be consumed by the external systems.
  * Action
    * Developed a framework to write appropriate extensions to inject this tokenizaiton/detokenizaiton and using Autofac DI and through configuration , all edges were taken care. This framework involved in application insights, tokenization/detokenization, Tenant level (for migration strategy).
  * Result
    * Tokenizaiton/Detokenization is the production with all sensitive data being encrypted in the system. Some of the pilot customers were migrated and validation is in the progress.
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
    * Enabling debug log levels on the fly for a given tenant , user and particular tranaction to troubleshoot.
  * Situation
    * Product is multi tenant and need a way to enable Debugging for a tenant and also for specific user and specific transaction. This was a requirement as some scnearios , support team wants to do analyze the DEBUG logs to trouble shoot issues.
  * Task
    * Come up with solution without changing any existing application code.
  * Action
    * As all applications are using log4net library , found there are interceptors one can write to interceptor to intercept the logging statemens and take action. Wrote custom interceptors which based on configuration redirect logging statements to DEBUG. 
  * Result
    * Today one can enable conditional loging (logs at USER,TENANT and TRANSACTION) and also with Auto turn off this feature (System will automatically turn OFF the DEBUG logs which will take care of any situations where support person forgets to turn OFF)
  * Challenges
    * Turn on debug for specific tenant without effecting performance hit in production. 
    * Need to manipulate log4net internals to come with solution to turn dynamic DEBUG for given tenant.
    * Auto On/Off feature for this tenant level DEBUG 

______

* HIS Framework
  * Purpose
    * Streamline the Core integration dev & test  & automation work
  * Situation
    * HIS is integration layer application which communicates to the core through different communiation, schema based on the backend service. Being legacy component it does not have any standards like interface approach, DI layers. This was making any new development to deveop new core integration is time consuming and developers were taking any where from 6months to 8 months.
  * Task
    * Develop framework for the developes to use to develop and concentrate develop effort just integration layer and let the framework take care of rest of the stuff (which integrates in to the application.) 
  * Action
    * Developed this framework with new design principles (like using SOLID principles) and integrate in thi integration layer.
  * Result
    * Today any new and existing development will make the development less than 1 month because of all layers (including unit and integraiton tests) were taken care by the framework.
  * Challenges
    * Develop framework to abstract the integration layer between Voyager and Core
    * Inject New DI  & Interface approach to the existing code and standardize the HIS development.

_____

* RC4 Migration ( to AES )
  * Purpose
    * Move away legacy RC4 C++ code which has memory leak (Microsoft deprecated this library which has leak)
  * Situation
    * Legacy Online transaction processor application was using RC4 encryption for some of the sensitive information. As this not secure and deeply integrated in C++ using Microsoft deprecated libraries , it is time to move to AES encryption. As there is huge volume of encrypted data exists already, there should be migration which cannot afford any application downtime.
  * Task
    * Identify all the C++ code where this RC4 encryption is used and come up with AES encryption along with on the fly migration to migrate as the users logging in to the application.
  * Action
    * Developed a .NET managed library code to integrate in to C++. Also a migration strategy to migrate RC4 data to AES as the users logging on to the system, which can be configured at tenant level.
  * Result
    * System with AES encryption for most of the tenants (as some of the tenants still not migrated)
  * Challenge
    * Voyager platform has deeply integrated with legacy C++ code. Moving this code in to new managed AES encryption.
    * Come up with migration strategy is challenging as we have large amounts of encrypted data and cannot afford to do offline migration

____

* Façade Service
  * Purpose
    * Expose voyager DCOM layer as WCF service, so that clients can remove our VLB (custom component to communicate to Voyager) and use as first class service.
  * Situation
    * Online Transaction processor is 22+ years of legacy C++ DCOM application with custom router component used by the clients. As modren client applications being developed and in order to use this application there was a need to for service which can abstract this DCOM application.
  * Task
    * Develop a service which can abstract the client applications for this DCOM application.
  * Action
    * A WCF Facade service was developed to interact with legacy application which can be used as first class service by the clients. This facade service hides all the complexity of this DCOM application expsoing higher level services.  
  * Result
    * All Clients has been updated to use this facade service and get rid of custom router component in these client applications.
  * Challenge
    * As Voyager requests and responses were legacy ( done long back) and these types were not 100% compatible with WCF data types.
    * Has to extend low level WCF Schema generator to make it Voyager SDK types to work.
    * Generation of the dynamic services based on SDK request and response types posed some challenges 

____

* Response Caching
  * Purpose
    * Cache package for API GET responses which are static for most of the time (This is part of client perf test)
  * Situation
    * A big client after migrating to the Platform observed significant latencies in users online sessions. During this period using dynaTrace monitoring tool , it was found that there are certain APIs is being called multiple times where the response does not change over the life time of user. As these APIs have significant backend calls along with decryption of certain fields can add some latency to the user sessions.
    We need to quickly fix this latency by caching the immutable responses.
  * Task
    * Identified all the calls which can be potentially cached and develop a common response caching mechanism which can give insights in to at API and method level , to reduce the number of calls. 
  * Action
    * Developed a package and using Autofac as DI , injected this caching in to application without changing the actual application code.
  * Result
    * As a result , the number of calls reduced and hence the performance of the application improved making client happy.
  *  Challenges
    * Incorporate these caching without modifying the existing code and come up with auto config changes (Turn on/off feature dynamically).
______

* Stand-in
  * Purpose
    * Divert the traffic to Stand-in server in case of Core down.
  * Situation
    * Online users of a specific tenant are not able to do financial functionality whenever bank core is down(either planned or unplanned). As part of high available and reliable effort, online users should be able to do functionality (even though it is limited with reduced functionality) when the bank core is down(either planned or unplanned).
  * Task
    * Design and develop a solution in the platform and integrate in to stand-in server which has already cached information.  
  * Action
    * Modified the applicaiton layer so divert the traffic in case of core functionality available (both manual and auto) to communicate to internal stand-in server and make  mark the  session such that UI can take run act with limited functionality.
  * Result
    * Online application works now even if the bank core is down (either planned or unplanned)
  * Challenge
    * TP (C++) code has been modified to incorporate.
    * Bringing min HIS layer in to TP (we will avoid HIS layer completely in case of transaction going to stand-in).
______

* Concurrent session feature
  * Purpose
    * Notifications to users whenever the user logins happening multiple times within same time.
  * Situation
    * Online Application needs detect multiple login sessions originating from different locations/browsers and send notification to the users for security purpose. 
  * Task
    * Need to enhanced to application layer to detect these scenarios and raise notifications.
  * Action
    * Enhanced C++ component to use Rules engine and Redis as queuing mechanism raise notifications.
  * Result
    * Application detects security related logins and raises notification.

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

* [RC4 vs AES](https://askanydifference.com/difference-between-aes-and-rc4-with-table/)
  * AES is a block cipher, while RC4 is a stream cipher. Block encryption and stream encryption are symmetric algorithm classifications. A block cipher encodes plain text in block sizes, while a stream cipher encodes bit by bit, which is similar to the flow of a stream
____

* Windbg
* Performance lab automation
* Automation tools
____