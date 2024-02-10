[zealvora](https://github.com/zealvora/certified-kubernetes-administrator)

* Difference between CMD and ENTRYPOINT
  * CMD can be overridden but not ENTRYPOINT
  * for ENTRYPOINT one can append arguments
* EXPOSE
  * is way of documenting by the image builder to inform the consumer about the port that container will expose
* Generating kubectl files
  * --dry-run=test -o yaml
* kubectl explain
  * kubectl explain pod 
  * kubectl explain pod.spec
  * kubectl explain pod.spec.containers
* labels
  * key/value pairs attached to objects
  * selectors allows us to filter objects based on labels.
* Replica set
  * maintains the desired state for pods
* Deployments
  * Rollout/Rollback
  * kubectl rollout history deployment.v1.apps/<depname>
  * maxSurge, maxUnavailable
    * maxSurge = 25% maxUnavailable=25%
    * Pods = 8
    * max: 10 and min=6
  * --record
* Jobs
* Service
  * Use selectors with labels
  * Types
    * Cluster IP
* Ingress
  * Ingress resource contains set of routnig rules based no which traffic is routed to a service.
  * Ingress Controller takes care of the Layer 7 proxy to implement ingress rules
  *  You must have an ingress controller to satisfy an Ingress. Only ceatin an Ingress resource has no effect
  * ingressClassName is important to associte controller
* Namespaces
  * Virtual clusters
  * Security can be provided by namespace
  * Team A for namespace A and Team B for namespace B etc.,
* Service Accounts
  * Permission
* Network security policy
  * ifconfig
* Secrets
  * [TYPE][NAME][DATA]
  * Generic
    * File
    * Directory
    * Literal
  * Docker registry
  * TLS
  * Using
    * Volumes
    * Environment variables
* Resources
  * Requests
  * Limits 
* Liveness Probe
  * Http
  * Command
  * TCP
( $? is the error code from last program run in linux)
* Readiness Probe
* Logging drive
  * json-file
  * none
  * syslog
  * local
  * jounald
  * splunk
  * awslogs
* Metrics server
* Events
  * TTL (default : 1hr)
  * kubectl get events
* Field selectors
  * Used for searching
* Docker volumes
  * df -h 
* Persistent Volumes
  * Persistent Volumn Claim
    * is a request for the storage by a user.
* ConfigMaps
  * Centrally store data
  * Dynamically changable.
  * kubectl create configmap [name][datasource]
    * File
    * Directory
    * Literal value
* Securty Context
  * runAsUser
  * runAsGroup
  * fsGroup
    * Applies the settings to the volumes.
* Design patterns for Multiple container PODs
  * Side car pattern
  * Ambasador pattern [here](https://learn.microsoft.com/en-us/azure/architecture/patterns/ambassador)
  * Adapter pattern (transform standarize/normalize)
* Deployment Strategy  
  * Recreate
    * Dev/Test
  * RollingUpdate

* Executing commands using Busybox
  * kubectl run curl --image=radial/busyboxplus:curl -i --tty
    * nslookup
  * kubectl attach <POD ID> -c curl -i -t
  * kubectl delete deployment curl 
    