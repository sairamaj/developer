# Active Directory
* __Active Directory__ is Microsoft trademarked for directory service
* Centralized and standardized system that automates network management of uesr data, security and distributed resources and enables inter operation with other directories.
* Designed for distributed networking environments.
* Support for the __X.500__ standard for global directories
* Hierarchical organization that provides a single point of access for system administration ( management of user accounts, clients, servers and applications)
* An object-oriented storage organization, which allows for easier access to information
* Support for the __Lightweight Directory Access Protocol__(LDAP) to enable inter directory operability


# LDAP
* Organized in a simple "tree" hierarchy with following levels
 * The root directory ( the starting place or the source of the tree) which branches out to
 * Countries, each of which branches out to
 * Organizations, which branches out to
 * Organizational units ( divisions, departments, and so forth) which branches out to 
 * Individuals (which includes people, files and shared resources such as printers)
* An LDAP directory can be distributed among many servers. Each server can have a replicated version of the total directory that is synchronized periodically. An LDAP server is called a Directory System Agent (DSA). An LDAP server that receives a request from a user takes responsibility for the request, passing it to other DSAs as necessary, but ensuring a single coordinated response for the user.

# LDAP Programming with .Net
* ADSI  ( Active Directory Service Interface)
* .NET 1.0+
    * System.DirectoryServices
       * .NET wrapper for ADSI
       * Any LDAP server
       * No strongly tped objects
* .Net 2.0+
    * System.DirectoryServices.Protocol
       * Skips ADSI, better performance/harder to use
* .NET 3.5+
    * System.DirectoryServices.AccountManagement
       * AD/ADLDS Only
       * User,Group,Computer objects only
       * Strongly typed objects
* Powershell
    * Module Active Directory 
       * Very similar to System.DirectoryService.AccountManagement

## Powershell
* Enable the "Active Directory module for Windows Powershell" feature
* From powershell window
    * Get-AdUser userid
    * Get-Command -Module ActiveDirectory

## Authentication to LDAP
* rootDSE ( every user able to read properties of it.)
### Using DirectoryEntry
```csharp
DirectoryEntry root = new DirectoryEntry("LDAP://rootDSE", UserName, Password, AuthenticationTypes.Secure);
using(root)
{
    var tmp = root.NativeObject ;       // will authentictate
}
```

### Using System.Directory.AccountManagement
```csharp
PrincipalContext adContext = new PrincipalContext(ContextType.Domain);
using(adContext)
{
    adContext.ValidateCredentials(UserName,Password)
}
```

### Using ASP.NET
```
  <connectionStrings>
    <add name="AdService"  connectionString="LDAP://demo.local" />
  </connectionStrings>

  
```

