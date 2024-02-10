* Tell me about yourself?
  * Hi good morning. Thanks for your time and this opportunity.
  * My name is Sairama Jamalapuram and you can refer me as Sai. 
  * I am a senior software advisor at Fiserv company which is leading fintech company. I have been with this company for last 24 years.
  * I work in Digital banking platform where we serve online banking for some of the larger banks across the world. 
  * In this role, I lead technical teams which consists of a team in US, 2 teams in India and a team in Costa-Rica. 
  * I am Responsible for designing and architecture of our product, consult with other groups in the company to integrate with other products. I am a hands-on architect. In order to advise the team right, I build POCs for new technical enhancements , build frameworks to prove out what works and doesn’t and use that to advise teams and also make them available to be consumed in our products.
  
 * Need to add
   * Taking the team from requirement to all the way production and monitoring.
   * Worked with different architecture styles?
     * Worked with Monolithic, Microsservice
   * Technical details?
     * Used to be primiarily work with C++ but for last 10 years working with .NET  
   * What I am looking for?
     * Looking for similar position for where I can do both high level design and architecture with some hands on. 
_____

* What are your strengths?
 * Self motivation, Quick learner, Positive attitude
   * I follow some principles in both my personal and professional
   * Always show positive attitude 
     * Belive 90% of things are good in this world
	 * One has to do whatever he is supposed to do 
	 * You help others and it will come back to one day or other
   * I apply these principles to professional
   * Growing in my early days we don't have internet (forget about internet, We don't have electricity till I was in 8th grade)
   * I wish I had the same luxury as these young kids have with internet where one can self learn in lot of things.
   * But instead of regretting, I make use of these to learn on regular basic both technology and personal issues.
  _______   
 * I never give up either it is professional or personnel.
   * One time there issue and needed socket level debugging and being application developer instead of giving it up, I learned enough socket programming and debugged a open software Stack Exchange Redis package and came up with some optimizations to solve the issue.
     * Details
		* Everything worked in during development as planned.
		* When we took this to our CERT region where we have lot of clients with lot of configuration data, things started failing with timeouts. We have to bring this time to reasonable value as this makes our application startup slower.
		* We could not use our Cert region for testing purpose.
		* We have to bring this big data to outside for testing and at the same time we cannot bring the same data outside the environment for security reasons.
		* I have to come up with different strategy with Azure, custom debugging of Stack Exchange implementation by learning Socket and Multiplexing and debug.
		* Found the issue that over head of ssl decryption of the many small pockets. At this time I wrote a optimized version of the collecting packets and doing ssl decryption on large packet.
  * I have mindset of nothing impossible either in professional or personnel within reasonable limits.
    * Professional
		* 
	* Personal
	  * Everest base camp example
	    * I had a miniscus tear in my right knee during a tennis game 5 years back and ever since I am not the same person I used to be.
		* When opportunity came to me from some of the friends who are making a trip to Everest base camp , I signed up and trained.
		* Inspite of good training , I did not feel good before my trip because falling sick 2 days before the trip.
		* I was determinied to go ahead anyway to see how far I can go.
		* Once I started the trip, I was able to continue by focusing and controlling my diet and made all the way including additional challenge which is making it to Kala Pathar.
	  * Tennis down 1-5 and came back win all the way.
		* I am a decent tennis player and play local tournaments. I had one time single tournament champion  one time.
		* While in this tournament, I was down 1-5 and close to get elimination and changed my strategy and kept telling myself that I can come back.
	    * I played with my new strategy which is balancing aggressive and defensive approach and came back finally to win that match.
_______
  * I have great learning new skills and debugging skills
	* Given new application and new code base , I can quickly understand and troubleshoot application issues.
	* As I am debug expert in our devision, I get calls other groups to get on to to production issues of their product. 
	* Most of these I will not have any context ,but need to find out quickly about their application and their code base.
    * One time I was involved with one of the production issue 	where application is crashing very frequently and its initialization causing big performance issue for their end users.
	* I asked them to setup a capture memory dump and got their memory dump and their code base. I analyzed their process memory dump and found a dead lock issue.
	* Used the Windbg extension and extracted all the .NET assemblies from memory dump.
	* With JetBrain dotnet Peek .NET reflector tool  analyzed their code base. 
	* Found the issue and recommended the short term and long term options to fix.
	* Also I observed some leaks especially with WCF cleans up, which is causing some memory objects to hang for long time causing Garbage collection spikes.
	* Usually I need to understand the whole architecture , code base and give suggestions for any potential issues , but scenarios like production issues where we don't have time to get full picture, I can still go from problem spot and expand to the new areas for the applications and it issues quickly.
____________________________________________________________________________

* What are your weakness?
  * Pronunciation
    * I have issue of pronouncing of some tough English words and this becomes issue now and then during my technical presentations. 
	* To overcome this I usually practice with online tools  before hand.
    * On the same lines I have habit of talking fast during my presentations and working on this by practicing my speaking with recording and listening and taking feedbacks from my colleagues.
	
_________________________

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
    * Has to come up with innovative way of Tenant level throttling using IIS and WCF internals.
    * Has to use some inner working of IIS to take care of these.

___________

* Architectural change in HIS to communicate to Core for parallel processing

  * Situation
    * A big client after migrating to the Platform observed significant latencies in users online sessions. After going through different layers of the application one issue was found that this client access to backend core has multiple calls to backend in order to gather user accounts information. Because of the serieal nature of this and based on the user profile some of these needed lot of calls and this was causing significant latency. The product had never framework to make these calls in parallel and asynchronous. This was high severity issue and also the legacy product does not have any framework and needed to be come up quick solution to make these calls async and parallel without effecting other tenant calls.

  * Task
    * Develop a framework for async, parallel calls with tenant thorttling and batch operations with timeouts incorporated.

  * Action
    * Used .NET TPL framework and simple memory queue architecture developed a framework where client plug-in can call to queue the batch operations and gather the responses.

  * Result
    * By incorporating batch operaitons client calls along with async and parallel, significant portion of the latency has been solved for the client making client happy.
       
  * Challenges
    * Whenever we introduce asynchronous and Parallel operations we need to take care of the following
    * Throttling ( Not to allow one Tenant to take complete resources)
    * Timeouts (In a set of operations some can succeed and some can timeout)
    * Queuing (we cannot spin threads to do parallel tasks) 

___________

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
    * Today we have all 3rd party calls go through this circuit breaker package and recover from any latency or failures from external systems. We never had this issue anytime after these changes in our production related to 3rd party issues.

  * Challenges
    * Develop package such that it can be integrated easily with external services without much changes to existing code.

_______

* Voltage Integration
  * Purpose
    * Voltage encryption feature in COASP across all Edges

  * Situation
    * There is enterprise level effort to implement standard encryption for data. This is to integrate with 3rd party Voltage for sensitive fields across the enterprise. We need to add this functionality across entire suite of products. This effort is to take care of all edges and once data enters in to the system should encrypt the data and traver within the layers as encrypted data.

  * Task
    * Identified all the edges and use appropriate framework extensions (like WCF  Behaviors for WCF services, HTTP extensions for REST API, Custom framework extension for custom applications) to integrate this tokenization/detokenization for sensitive fields. Migration has been idenfied as big tasks as the current system is multitenant and huge data exists in the system which needs to be encrypted without taking the system down. There were number of batch job applications which were either consuming external data or producing the data to be consumed by the external systems.

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
    * I went though Redis cache architecture, gone through Redis API and also gone through teams implementation in their web app. On the surface everything looked right. I went through the dev system where it is work ingfine and then Performance lab where it did not work. Found one big difference is the data and how these has been organized in to Redis Cache in the code. It turned out the team has came up with 4 big keys and each key containing a big json blob which has 150MB each. From the redis documentation found that Redis works great with more keys and less value data. But the team went too far with implementation and also in order to compatible with their legacy code , they said it will take long time to implement the new way. At this point I have no chice other than to see whether with any minimal change I can make this work. I have downloaded .NET implementation of redis by Stackexchange library and went through the code and debugged where the latency is. In the process I have to understand some socket programming and some multiplexing logic in this library. Ultimately found by tweking some inner working of this library we can make things faster. The latency is happening because of decryption of this large data. The default implementation is doing decypting the small chunks of 4K as the data is received causing the high CPU and hence latency. At this point implemented read buffer option in the library where enabled , the response chunks are collected and at the end one decryption is done. Also application logic has to be split in to some more keys to track updates, deletes and additions. Instead of taking the updates to any configuration and update the redis value, these updates were tracked separately and merged in to the application memory. Same approach has been taken care of deletes and additions.  

  * Result
     Out deployment is used this custom stack exchange and the web app was able to successful in loading. Over the peroid of time the data grew (because of clients as this app is multi tenant) and still the web app is workinas expected till today.

  * Category
    * Give me an example of a difficult problem you solved. How did you solve this problem
______
		
* Conditional Logging
  * Purpose
    * Enabling debug log levels on the fly for a given tenant , user and particular tranaction to troubleshoot.
  
  * Situation
    * Product is multi tenant and need a way to enable debugging for a tenant and also for specific user and specific transaction. This was a requirement as some scnearios , support team wants to do analyze the DEBUG logs to trouble shoot issues.

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
    * Cache package for API GET responses which are static for most of the time (This is part of 
    client perf test)

  * Situation
    * A big client after migrating to the Platform observed significant latencies in users online sessions. During this period using dynaTrace monitoring tool , it was found that there are certain APIs is being called multiple times where the response does not change over the life time of user. As these APIs have significant backend calls along with decryption of certain fields can add some latency to the user sessions.We need to quickly fix this latency by caching the immutable responses.

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

