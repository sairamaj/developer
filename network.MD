# Network Topologies
## Bus (old)
* Single long cable
* Terminators on either side of cable
* Devices connect using short patch cables
* No centralized hub or switches

## Star (common)
* Central connectivity to hub or switch
* Cable breaks do not affect the network
* Short patch cables are used for connectivity

 ## Ring
 * Physical Ring
  * Devices have two network connections
  * Dual counter-rotating rings
  * Fiber Distributed Data Interface (FDDI)
* Logical ring
  * Devices have one network connection
  * Physically wired as star
  * Token Ring

  ## Mesh
  * Multiple topologies linked together
  * Common in WAN environments
  * Topology adapters
  * Device topology connectors

  # Short Range Network Types
  * PAN (Personnel Area Network)
  * LAN (Local Area Network)
  * CAN (Campus Area Network)

  # Long Range Network Types
  * WAN (Wide Area Network)
  * MAN (Metropolitan Area Network)
  * GAN (Global Area Network)


# ![OSI](https://github.com/sairamaj/developer/blob/master/images/osi.png)
# ![Protocol and OSI](https://github.com/sairamaj/developer/blob/master/images/protocolandosi.png)

# Transmission Media Access
* IEEE 802.3: Ethernet
* IEEE 802.5: Token ring
* Wi-Fi

# Network Interface Card
* Unique 48-bit MAC address
* Required for network connectivity
* A single host can have multiple NICs

# Repeater
* Regenerating digital signals - repeater
* Regenerating analog signals - Amplifier
* Allows for long distances
* UTP cables have maximum distance of 100m

# Hub
* OSI model layer 1(Physical layer)
* Central wiring location for wired network devices
* All hub ports see traffic for all ports
* High possibility of pocket collisions
* Can function as repeater

# Network Bridge
* OSI model layer 2( Data link layer)
* Remembers which MAC addresses are plugged in to which bridge ports
* Transparent to higher-level protocols such as TCP/IP
* Wireless bridging
* Can function as repeater

# Network Switch
* OSI model layer 2(Data link layer)
* OSI model layer 3(Network layer) switches support routing
* Remember which MAC addresses are plugged into switch ports.
* MAC address table in memory
* VLANs

# Network Router
* Route network transmissions to other networks
* OSI model layer 3(Network layer)
* IP addresses
* Multiple network interfaces
* Routing tablen

## Ports
* OSI model layer 4 addresses
* Are either TCP or UDP
* Uniquely identify a network service
* Well known ports 0-1023
* Malicious users scan  for port numbers
* Host + port number = socket
* Port numbers are 2 way streets

## DNS
* Name look up service
* Listen for client queires on port 53
* Fully qualified names resolved to ip addresses
* ip addresses are resolved to fully qualified names

## DNS Record types
* SOA - Start of authority
* NS - Name server
* A - IP4 forward lookup
* AAAA - IPV6 forward lookup
* PTR  - Reverse lookup
* CNAME - Alias
* MX - Mail exchanger

## DNS tools
* ping
* ipconfig /all
* ipconfig /flushdns
* nslookup
* dig
* cat etc/resolve.conf

## IP
* Responsible for routing
* Concerned with IP address
* OSI model layer 3 ( network layer)
* Routers

## TCP
* Reliable
* Connections oriented
* Every packet must be acknowledged

## UDP
* Unreliable
* Connectionless
* Packet acknowledgments not used
* Stateless

## ICMP (Intrernet Control Message Protocol)
* Reports host and network options
* Used by ping command
* Used by tracert command

# ARP (Adress resolution protocol)
* Used on a LAN
* Broadcast based
* Resolve IP address to Mac Addresses.

## IP Address Config
* IP Address ( 198.168.1.45)
* Subnet 
  * separates the host and network portions of an IP address
  * ex: ( 255.255.255.0) (with above IP, the network is:198.168.1 and host is:45)
* Default Gateway (exit door - transmit traffic outside our LAN - it has to be on the same subnet)
* DNS ( don't need to be on the same net. at least 2 needs to be configured.)
* First portion of IP ( Class A 1-126 , Class-B 128-191 , Class-C 192-223)
* tracert - (let you find how many routers are being used in path.)

## CND ( Computer Network Defence)
* Firewalls
* Security Information and Event Management(SIEMS)
* Intrusion Detection System (IDS)
* Intrusion Prevention Systems (IPS)
* Public Key Infrastructure (PKI)


(SSH is secure of telnet)
(todo: see whether any network simulator)


