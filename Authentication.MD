### nonce
In cryptography, a nonce is an arbitrary number that may only be used once. It is often a random or pseudo-random number issued in an authentication protocol to ensure that old communications cannot be reused in replay attacks.

### SAML,OpenID,OAuth
* SAML is for enterprise authentication (XML)
* Open Id is consumer authenication (JSON)
* OAuth is authorization ( API authorization)

### Security Token 
* Security token are protected data structures
    * contain information about issuer and subject(claims)
    * signed(tamper proof& authenticity)
    * typically contain expiration time
* A client requests a token
* An issuer issues a token
* A resources consumes a token
    * has a trust relationship with issuer.
* Types
    * SAML ( XML )
    * JWT (JSON)

### JSON Web token(JWT)
* Header
    * metadata
    * algorithm & keys used
* Claims
    * Issuer(iss)
    * Audience(aud)
    * IssuedAt(iat)
    * Expiration(exp)
    * Subject(sub)
    * ... application defined claims
# ![jwt](https://github.com/sairamaj/developer/blob/master/images/jwt.png)

### OAuth2
* An open protocol to allow secure authorization in a smple and standard method from web, mobile and desktop applications.
    * Client (is software that is used to access backend)
    * Resource Owner ( is human that owns the backend data)
### OAuth Players
# ![jwt](https://github.com/sairamaj/developer/blob/master/images/oauthplayers.png)

### Open Id Connect
* OpenID Connect builds on top of OAuth2
    * Authorization Code Flow
    * Implicit Flow
* Adds some new concepts
    * ID token
    * UserInfo end point
* and some additional protocols 
    * discovery & dynamic registration
    * session management
    
[OAuth Integration](https://oauth.io/home)





