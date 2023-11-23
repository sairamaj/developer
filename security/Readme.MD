# CSRF (Cross Side Request Forgery)
## Problem
* user visits example.com
* user visits hacker.com
* hacker.com posts a change email to example.com through java script 
![csrattackscript](https://github.com/sairamaj/developer/blob/master/images/csrfattackscript.png)

## Fixing
* Append anti CSRF token to the request.
* should be unique and unpredictable.
* email=xx&action=yy&anti-csrf=somethingunique

# Login CSRF Attack
![logincsrfattack](https://github.com/sairamaj/developer/blob/master/images/logincsrfattack.png)

## Fixing
* Append anti CSRF token to the login request.

# Security 
* Least Privilege
    * Deny first - allow case by case
* Secure by Default
    * Design the application securely from teh start. Integrate security into your development lifecycle.
    * Defence in depth
    * Enable safe security settings by default. Both application and infrastructure
    * Disable any unused services or functionality.
* Defence in Depth    
    * Data layer: Access controls, Encryption, Backup and restore
    * Application layer: Authentication, Authorization, Auditing (AAA). Secure coding and hardening
    * Host layer: Hardening, Authentication, Patch
    * Internal network: Network segmentation, IPsec, TLS, NAT
    * Preimeter layer: Firewalls, TLS, Denial of service, prevention
    * Physical Security: Guards, Locks, Tracking devices and badgeting system.
* Robust error checking
    * Stack trace and infrastrucutre should not be leaked.
* Trust No Input
* Fail Securely
* Reuse existing security controls in a framework.
    * keep simplicity
    * reusing existing and proven code frameworks
* Logging vulnerabliities
    * 5Ws 
        * What happended
        * When
        * Where
        * Who
        * Where dit it come from
* Open Design
    * Don't rely solely on "security through obscurity".
    * Security controls should be based on pen and known principles. 
* Data Protection
    * Never hard code secret information in source code.
    * Don't store database credentials or encryption keys in plain text.
    * Securely store all sensitive user information.
    * Send trafic over a secure communication channel
    * Inform users about the privcy poicy that has been implemented.

## Web Security
* In sufficient HTTP headers missing
    * X-XSSS-Protection
    * X-Content-Type-Options
    * Content Security Policy
    * X-Permited-Cross-Domain-Prolicies 
    * Content-Type
    * X-Frame-Options

    * Remove X-Powered by headers
* Cookies and Sessions
    * SECURE - Avoid tranmission over an insecure channel.
    * HTTPONLY - Don't let Javascript read a cookie's value.
    * DOMAIN - Set the domain for which the cookie is available.
    * PATH - Set subfolder and pages for which the cookie is available.
    * EXPIRES - Determine when the cookie should be deleted.
    
* MAC
  * Message Authentication Code
  * Concept of combining Message + Secret Key when calculating Digest
  * Provies **Integrity** and **Authentication** for bulk data transfer
  * HMAC - Industry standard implementation of MAC (tells how one will combine the message + key)
    