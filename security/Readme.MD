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