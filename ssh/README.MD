## Overview of SSH and keys
SSH is an encrypted connection protocol that allows secure sign-ins over unsecured connections. It is the default connection protocol for Linux VMs hosted in Azure. Although SSH itself provides an encrypted connection, using passwords with SSH connections still leaves the VM vulnerable to brute-force attacks or guessing of passwords. A more secure and preferred method of connecting to a VM using SSH is by using a public-private key pair, also known as SSH keys.

The public key is placed on your Linux VM, or any other service that you wish to use with public-key cryptography.

The private key is what you present to your Linux VM when you make an SSH connection, to verify your identity. Protect this private key. Do not share it.

Depending on your organization's security policies, you can reuse a single public-private key pair to access multiple Azure VMs and services. You do not need a separate pair of keys for each VM or service you wish to access.

Your public key can be shared with anyone; but only you (or your local security infrastructure) possess your private key.

### Private key passphrase
The SSH private key should have a very secure passphrase to safeguard it. This passphrase is just to access the private SSH key file and is not the user account password. When you add a passphrase to your SSH key, it encrypts the private key using 128-bit AES, so that the private key is useless without the passphrase to decrypt it. If an attacker stole your private key and that key did not have a passphrase, they would be able to use that private key to log in to any servers that have the corresponding public key. If a private key is protected by a passphrase, it cannot be used by that attacker, providing an additional layer of security for your infrastructure on Azure.

