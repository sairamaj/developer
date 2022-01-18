* Certified Azure Solution Architect : (Passed AZ 303 & AZ 304 recently)

### My work in recent years
* COASP Self Service Portal
  * Purpose
    * Enable every user to quickly bring up the COASP environments through self service portal.
  * Challenges
    * Not a official project ( weekend and some free time slots)
    * Gives the ability to automate the COASP daily builds as Azure templates
	* One can create a given COASP Azure environment in 5mins (complete isolated working) through web portal
    * Used the Blazor framework (which gives us some cool features like C# code in browser)

_____

* TP Redis
  * Purpose
    *	Make TP session stateless (Making user session reliable and protect from TP failures)
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
  * Challenges
    * The number of configuration items and its partition gave lot of performance issues during the initial testing.
    * Need to come up with StackExchange fixes which involved some optimization at Socket programming level.

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

