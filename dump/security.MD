* Symmetric encryption
  * the term block size refers to the number of bits that are processed at a time by the encryption algorithm. There are two types of ciphers in symmetric encryption: stream ciphers and block ciphers. Stream ciphers encrypt/decrypt the message one bit at a time, while block ciphers encrypt/decrypt the message block by block, with each block referring to a group of bits 123.

  * The block size is the basic unit of data that can be encrypted or decrypted in one operation. Messages longer than the block size are handled as successive blocks, while messages shorter than the block size must be padded with extra bits to reach the size of a block 4. The valid block sizes are determined by the symmetric algorithm used 4.
  * The relationship between block size and security in symmetric encryption is not straightforward. A larger block size does not necessarily mean that the encryption is more secure. In fact, a larger block size can sometimes lead to slower encryption and decryption times 12.
  * The security of a symmetric encryption algorithm depends on several factors, including the key size, the block size, and the encryption mode used. A larger key size generally means that the encryption is more secure, but it also requires more processing power to encrypt and decrypt the message 134.
  * In general, a block size of 128 bits is considered to be secure for most applications 13. However, some encryption algorithms, such as the Blowfish cipher, use a block size of 64 bits and are still considered to be secure 12
  * The relationship between key size and security in symmetric encryption is not straightforward. A larger key size generally means that the encryption is more secure, but it also requires more processing power to encrypt and decrypt the message 123.
  * In typical symmetric encryption algorithms, the key is quite literally just a random number in left[0..2nright], where n is the key length 1. The strength of the key is based upon its resistance to brute-force attacks, where an attacker would need to perform an attack with complexity Oleft(2nright) to correctly guess the key 1.
  * The recommended key size for symmetric encryption is 128 bits for most applications 12. However, some encryption algorithms, such as the Blowfish cipher, use a key size of 448 bits and are still considered to be secure 13.
  * In general, a larger key size provides more security, but it also requires more processing power to encrypt and decrypt the message. Therefore, the key size should be chosen based on the level of security required and the processing power available 123.

  * In the context of symmetric encryption, iteration count refers to the number of times that a password is hashed during the derivation of the symmetric key 12. The higher the iteration count, the more difficult it is to validate a password guess and then derive the correct key 2.

  * The iteration count is used together with the salt to prevent against attacks using rainbow tables 2. Rainbow tables are precomputed tables used in cryptanalysis to crack password hashes 3. By increasing the iteration count, the time required to generate a rainbow table increases, making it more difficult for an attacker to crack the password 2.

  * For example, the AesManaged class in .NET uses the Password-Based Key Derivation Function 2 (PBKDF2) algorithm to derive the symmetric key from the password 1. The iteration count is one of the parameters of the PBKDF2 algorithm 2. The default iteration count for the AesManaged class in .NET is 10,000 1.
  * An IV is essential when the same key might ever be used to encrypt more than one message.
     The reason is because, under most encryption modes, two messages encrypted with the same key can be analyzed together. In a simple stream cipher, for instance, XORing two ciphertexts encrypted with the same key results in the XOR of the two messages, from which the plaintext can be easily extracted using traditional cryptanalysis techniques.
  * In symmetric encryption, both the initialization vector (IV) and salt are used to enhance the security of the encryption process, but they serve different purposes.
    * The IV is used to randomize the input data and hide patterns in the encrypted data while avoiding the re-issuing of a new key after each invocation 13. The IV is mixed with the first block of data to be encrypted to initiate the encryption process 1. The IV is typically required to be of the same size as the cipher’s block size 1.
    * On the other hand, salt is used to prevent pre-computation attacks 1. A pre-computation attack is an attack where an attacker pre computes a table of possible keys and their corresponding cipher texts before the actual encryption takes place. The attacker can then use this table to quickly decrypt the cipher texts. By adding a salt to the plaintext before encryption, the attacker’s precomputed table becomes useless.
    * In summary, the IV is used to randomize the input data and hide patterns in the encrypted data, while the salt is used to prevent pre-computation attacks.
  * __WebInspect__ is a dynamic application security testing (DAST) tool that identifies application vulnerabilities in deployed web applications and services. It is designed to help security professionals assess potential security flaws in web applications by performing attacks. WebInspect scans modern frameworks and web technology with the most comprehensive and accurate dynamic scanner. It can scan RESTful web services, client-side software, and APIs, and provides functional, hacker-level, and enterprise-wide insights 3. WebInspect integrates with various security testing and management systems, and supports automation, agent technology, and compliance management.
  * __Sonatype__ is a company that provides software supply chain management for organizations that use open source code in their development 1. It offers a platform that analyzes and secures open source components, and helps developers, security professionals, and legal teams collaborate and innovate 1. Sonatype’s platform empowers speed and security in open source development, giving organizations total control of their SDLC (Software Development Life Cycle) for more confidence in every piece of open source code, source code, and containerized code 1. Sonatype has been recognized as an award-winning workplace for innovators.
  
  ____
  * Cipher Block Chaining (CBC) and Galois/Counter Mode (GCM) are two modes of operation for symmetric-key cryptographic block ciphers. Both modes provide confidentiality, but GCM also provides data authenticity (integrity) .
  * In CBC mode, each plaintext block is XORed with the previous ciphertext block before being encrypted with the key 3. This makes CBC vulnerable to a number of attacks, such as padding oracle attacks, if the same key and IV are used more than once 1. CBC is not parallelizable and lacks built-in authentication 1.
  * In GCM mode, the encryption process is similar to that of counter mode (CTR), where each plaintext block is XORed with a unique counter value before being encrypted with the key 3. GCM uses arithmetic in the Galois field GF(2^128) to compute the authentication tag, which is then appended to the ciphertext 1. GCM is parallelizable and has built-in authentication, making it faster and more secure than CBC 12.
  ____

* Misc
  * Guardian
  * Palo alto
  * iOvation
  * Onespan
  * Radware WAF
  * Vanity Certificate
    * A vanity certificate is a type of SSL/TLS certificate that is used to secure a specific domain name or subdomain 1. It is also known as a private SSL certificate or custom SSL certificate 1. Vanity certificates are typically used by businesses that want to secure their website with a certificate that has their company name in it, rather than the name of the certificate authority.
  * TransUnion