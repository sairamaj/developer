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
# ![oauth players](https://github.com/sairamaj/developer/blob/master/images/oauthplayers.PNG)

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


## Mutual Authentication
Mutual SSL authentication or certificate based mutual authentication refers to two parties authenticating each other through verifying the provided digital certificate so that both parties are assured of the others' identity. In technology terms, it refers to a client (web browser or client application) authenticating themselves to a server (website or server application) and that server also authenticating itself to the client through verifying the public key certificate/digital certificate issued by the trusted Certificate Authorities (CAs). Because authentication relies on digital certificates, certification authorities such as Verisign or Microsoft Certificate Server are an important part of the mutual authentication process. From a high-level point of view, the process of authenticating and establishing an encrypted channel using certificate-based mutual authentication involves the following steps:

* A client requests access to a protected resource.
* The server presents its certificate to the client.
* The client verifies the server’s certificate.
* If  successful, the client sends its certificate to the server.
* The server verifies the client’s credentials.
* If successful, the server grants access to the protected resource requested by the client.

# ![mutual authentication](https://github.com/sairamaj/developer/blob/master/images/mutualauthentication.png)
[Source](https://www.codeproject.com/Articles/326574/An-Introduction-to-Mutual-SSL-Authentication)

