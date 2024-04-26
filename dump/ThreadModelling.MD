* Definition
  * The art of predicting possible disasters and figuring out how to stop them.
* 3 pieces
  * Target (has something value)
  * Threat vector (way of attacking)
  * Threat Actor
* The only truly secure system is one that is powered off, cast in a block box concrete and sealed in a lead-lined room with armed guards.
* The goal is to move from reactive security posture to a proactive thread hunting model.
* Approaches
 * Asset-centric (rick-centric)
   * list of assets
     * email address database
     * web server
   * methodoligies
     * **P**rocess **A**ttack **S**imulation **T**hreat **A**nalysis
 * Attacker-centric
   * list of actors
 * Application-centric
  * Visualizing the application components, processes, data flow and actors.
  * VUse thread classification models to identify potential threads.
    * STRIDE
    * OWASP top 10
  * Generate list of threats.

* Microsoft Threat Modeling (not just STRIDE but more)
  * Identify the assets
  * Create architecture overview
    * Visualize the flow of data, its subsystems and trust boundaries through a dataflow diagram.
  * Decompose the application
    * Vulnerabilities hiding in design, implementation and deployment configurations are revealed.
  * Identity threats
    * You can pinpoint the potential dangers your application may face.
  * Documenting threats
    * EAch identified threat needs to b e recorded & comprehensive visibility needs to b ensured.
  * Rating threats
    * OWASP risk rating 
    * CVSS
    * DREAD
* **O**perationally **C**ritically **T**hreat **A**sset **V**ulnerability **E**valuation (OCTAVE)
* VAST modelling

___
### Exercise
* Define Assets
  * E-mail address database.
  * CMS user database
  * Content database
  * Web server.
  * Database server
  * Mail server
* In Scope
  * E-mail address database
  * CMS user database
  * Content database
* Out of scope
  * Web server
  * Database server
  * Mail server
___

* Data Flow Diagrams
  * Process (Rounded rectangle)
  * Arrow (data flow from one element to another)
  * External entity (rectangle)
  * Dotted line (Trust boundary)

___

* Analyzing the targets
  * Security Profile
    * Input validation
    * Authentication
    * Authorization
    * Configuration management
    * Sensitive data
    * Session management
    * Cryptography
    * Parameter manipulation
    * Exception management
    * Auditing and logging
    * .. more based on project

___

* Identifying the threats
  * __STRIDE__ (helps us identify different types of threats)
    * **S**poofing
      * The art of pretending to be someone or something else, essentially violating authentication.
    * **T**ampering
    * **R**epudiation
      * You are not responsible for the actions (missing audit trails)
    * **I**nformation disclosure
      * Providing unauthorized individuals with access to sensitive information.
    * **D**enial of service
    * **E**levation of privilege
      * Someone gains the ability to perform actions that they should not be allowed to.
STRIDE model - can examine each data flow and elements in our data flow diagram to uncover more threats.

* Other models
  * Attack Libraries
  * Attack Trees
  * DESIST
___

* Document threats
  * Securing application
  * Countermeasure
  * The attack technique
  * Target

___

* Rate threats
  * Helps us prioritize risks and enables development teams to fucus their efforts on implementing counter-measures or mitigations.
  * Classifications
    * DREAD (3 - High , 2 -Medium 1- Low)
      * Damage Potential
      * Reproducibility
      * Exploitability
      * Affected Users
      * Discoverability


___

### SDL Threat MOdeling PRocess and Workflow
* 5 steps
  * Protection and defining security objectives
  * Creating diagrams and tables
  * Identify potential vulnerabilities
  * Mitigating threats
  * Confirmation threat mitigation


## Misc (move this to architecture)
[Documenting architecture Decisions](https://cognitect.com/blog/2011/11/15/documenting-architecture-decisions)
[Markdown any decision records](https://github.com/adr/madr)

