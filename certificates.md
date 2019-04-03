* certificate
    * A digitally signed statement that contains information about an entity and the entity's public key, thus binding these two pieces of information together. A certificate is issued by a trusted organization (or entity) called a certification authority (CA) after the CA has verified that the entity is who it says it is.
    Certificates can contain different types of data. For example, an X.509 certificate includes the format of the certificate, the serial number of the certificate, the algorithm used to sign the certificate, the name of the CA that issued the certificate, the name and public key of the entity requesting the certificate, and the CA's signature.
* certificate revocation list (CRL) 
    * A document maintained and published by a certification authority(CA) that lists certificates by the CA that are no long valid.
* certificate trust list
    * (CTL) A predefined list of items that have been signed by a trusted entity. A CTL can be anything, such as a list of hashes of certificates, or a list of file names. All the items in the list are authenticated(approved) by the signing entity.

### physical certificate stores
* The physical certificate stores are where public-key objects such as certificates, CRLs, and CTLs are physically stored either locally in the system registry of the computer or remotely in Active Directory. Many of the public-key objects in the physical stores are shared among users, services, and computers through the use of logical certificate stores.


### Logical certificate stores
* Logical certificate stores group certificates together in logical, functional categories for users, computers, and services. Logical certificate stores contain pointers to the physical certificate stores.The use of logical certificate stores eliminates the necessity of storing duplicates of common public key objects, such as trusted root certificates, CTLs, and CRLs for users, computers, and services
    * Personnal
        * Contains individual certificates for the user, service, or computer. For example, when an enterprise CA issues you a User certificate, the certificate is installed in the Personal store for your user account
    * Trusted Root Certification Authorities
        * Contains certificates for root CAs. Certificates with a certification path to a root CA certificate are trusted by the computer for all valid purposes of the certificate
    * Enterprise Trust
        * Contains CTLs. Certificates with a certification path to a CTL are trusted by the computer for purposes specified in the CTL.
    * Intermediate Certification Authorities
        * Contains certificates for CAs that are not trusted root certificates (for example, certificates of subordinate CAs), but that are required to validate certification paths. This store also contains CRLs for use by the user, service, or computer.
    * Active Directory User Object
        * Contains certificates that are published in Active Directory for the user. This store appears in the Certificates console for users only, not for computers or services.    
    * Request 
        * Contains pending or rejected certificate requests. This store appears only in the Certificates console after a certificate request has been made for the user, computer, or service.
    * SPC
        * Contains certificates for software publishers that are trusted by the computer. Software that has been digitally signed by publishers with certificates in this store is downloaded without prompting the user. By default, this store is empty. When Microsoft® Internet Explorer downloads software that has been signed by a software publisher for the first time, users are prompted to choose whether they want to trust all software that is signed by this publisher. If a user chooses to trust all software signed by the publisher, the publisher's software publisher certificate (SPC) is added to the SPC store. This store appears in the Certificates console for the local computer only, not for users or services.


[Eight tips for working with X.509 certificates in .NET](http://paulstovell.com/blog/x509certificate2)

# PEM file in windows
* Export as pfx
* Use openssl
    * openssl pkcs12 -in input.pfx -out output.pem -nodes

[Eight tips for working with X.509 certificates in .NET](http://paulstovell.com/blog/x509certificate2)
[.crt .key to .pfx](https://www.sherweb.com/blog/when-given-crt-and-key-files-make-a-pfx-file/)
## CSR
[What is a CSR (Certificate Signing Request)?
](https://www.sslshopper.com/what-is-a-csr-certificate-signing-request.html)

## Formats of Certificates
[source](https://www.tutorialsteacher.com/https/ssl-certificate-format)
![formats](https://github.com/sairamaj/developer/blob/master/images/certformats.jpg)

[converters](https://www.sslshopper.com/ssl-converter.html)

.pfx contains both public and private key and usually .cer contains public key and .key contains private key




