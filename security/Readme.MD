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

