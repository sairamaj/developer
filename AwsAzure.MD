## Cloud Infrastructure models
* Public
    * Azure, AWS
* Private
    * OpenStack (linux based)
    * System Center ( Azure stack, 2016)
* Hybrid
    * Secure private connection between private and public clouds

## Cloud Delivery models
* Saas
    * End user applications ( google apps, Office 365)
    * Target: customer
* Paas
    * Developer focused (AWS Elastic Beanstalk, Azure app service )
    * Environment for creating Apis, browser based applications 
    * Target: developer
* IaaS
    * Infrastructure as service (AWS EC2, Azure Virtual machines)
    * Target: sysadmins

## Creating Web App 
* AWS
    * Elastic bean
* Azure
    * App services

#### Deployment Architecture 
* Azure - Resource Manager
* AWS   - CloudFormation

## IaaS
* Azure
    * Billed in Minutes (If you use 10 mins it is charged 10mins)
    * Virtual disks are stored in storage blobs
    * Virtual network
* AWS
    * Billed in Hour ( if you use 10 mins it is charged 1hr)
    * Virtual disks are stored in EBS (Elastic Block storage)
    * VPC (Virtual Private Cloud)
    * Use ssh (powershell or standalone tool) to connect
        * In powershell
            * ssh -i foo.pem user

[Public cloud cost comparison](https://calculator.unigma.com/#/instances)

## SaaS
Sofware as a service. A software licensing and delivery model in which software is licensed on a subscription basis and is centrally hosted.
ex: Office 365

