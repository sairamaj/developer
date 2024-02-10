Below are steps to learn _docker_, _kubernetes_, _istio_ if you have docker on your machine.
__

* Copy curl and put it your path
  * If you prefer you can use powershell Invoke-WebRequest, but curl is easy to test for simple things.
  * [download](https://curl.se/download.html)
  * Test

    ```cmd
        curl -v www.google.com
    ```

_______________

#### Docker

* docker run hello-world
* docker run -p 8000:80 httpd
* In another command window

  ```cmd
    curl http://localhost:8000**
  ```

* docker run -p 8001:80 kennethreitz/httpbin
* [info](https://httpbin.org/)
* In another command window

  ```cmd
      curl -v http://localhost:8001/get
      curl -v http://localhost:8001/status/500
      curl -v http://localhost:8001/status/200
  ```

__

#### Kubectl

##### Deploying POD

* create pod
  
  ```cmd
    kubectl apply -f deploy-httpd.yaml
    ```

* We need _kubectl_ port forwarding to access this pod which is not standard but useful in testing a single POD.
  
* Test

  ```cmd
    curl http://localhost:8000
  ```

  ```html
    <html><body><h1>It works!</h1></body></html>
  ```

##### Deploying Service

We need a service to expose the above POD which can be accessed by clients as accessing single POD is not desirable.

* service deploy
  
  ```cmd
    kubectl apply -f service-httpd_nodeport.yaml
  ```

  ```cmd
    httpd-service   NodePort    10.111.25.39   <none>        9000:30077/TCP   17m
  ```

  * Test

    ```cmd
    curl http://localhost:30077
    ```
  
  * In above we have exposed service as _NodePort_ so that we can communicate to it externally. In reality we will use _ingress_ (which we will do later). Also see the port _30077_ we have used.
  
__

##### Deploying Ingress

We have exposed service node port and used it to access externally. But in real scenario one will use _ingress_ and _ingress controller_ to access the various services.

* Deploy ingress
  
  ```yaml
    # https://kubernetes.io/docs/concepts/services-networking/ingress/#the-ingress-resource

    apiVersion: networking.k8s.io/v1
    kind: Ingress
    metadata:
      name: my-test-ingress
      namespace: default
      #annotations:
        # nginx.ingress.kubernetes.io/rewrite-target: /
    spec:
      ingressClassName: nginx
      rules:
      - host: kubetest.sairama.com
        http:
          paths:
          - path: /
            pathType: Prefix
            backend:
              service:
                name: httpd-service
                port:
                  number: 80
  ```
  
  ```cmd
    REM use ClusterIP now for the service
    kubectl apply -f service-httpd.yaml
    kubectl apply -f ingress.yaml
    kubectl get svc
    kubectl get ingress
  ```

  ```cmd
    httpd-service   ClusterIP   10.111.25.39   <none>        9000/TCP   157m
    my-test-ingress   nginx   kubetest.sairama.com   localhost   80      37h
  ```

* One need _ingress controller_ to actually make it work (_ingress_ is just defining , think of as contract and _ingress controller_ is the one actually implements and make things happen)

* Deploy Ingress Controller
  
  ```cmd
    kubectl apply -f https://raw.githubusercontent.com/kubernetes/ingress-nginx/controller-v1.8.2/deploy/static/provider/cloud/deploy.yaml
    kubectl get pods -n ingress-nginx
  ```

* Wait for some time for the controller to be ready.
  
  ```cmd
    kubectl get pods -n ingress-nginx
  ```

  ```cmd
    ingress-nginx-admission-create-hqd2j        0/1     Completed   0          2m30s
    ingress-nginx-admission-patch-tdtnm         0/1     Completed   0          2m30s
    ingress-nginx-controller-6f4df7b5d6-rtjgj   1/1     Running     0          2m30s
  ```

* See the ingress details

  ```cmd
    kubectl describe ingress my-test-ingress
  ```

  ```cmd
    Name:             my-test-ingress
    Labels:           <none>
    Namespace:        default
    Address:          localhost
    Ingress Class:    nginx
    Default backend:  <default>
    Rules:
      Host                  Path  Backends
      ----                  ----  --------
      kubetest.sairama.com
                            /   httpd-service:80 (10.1.1.51:80)
    Annotations:            <none>
    Events:
      Type    Reason  Age                   From                      Message
      ----    ------  ----                  ----                      -------
      Normal  Sync    2m14s (x2 over 3m7s)  nginx-ingress-controller  Scheduled for sync
  ```
  
  * Test

    ```cmd
      curl -v --resolve kubetest.sairama.com:80:<localipaddress> http://kubetest.sairama.com/
    ```

* Add another service at the same site with different path.
  * Deploy httpbin POD
  
    ```cmd
      kubectl apply -f deploy-httpbin.yml
    ```

    * Test it
      * Use kubectl port forward
      * Use curl

      ```cmd
        kubectl port-forward  httpbin-app 8000:80
        curl http://localhost:8000/json
      ```

  * Deploy httpbin Service
  
    ```cmd
      kubectl apply -f ingress_2.yaml
      kubectl describe ingress my-test-ingress
    ```

  * Deploy Ingress
  
    ```cmd
      kubectl apply -f ingress_2.yaml
    ```

    ```cmd
          Rules:
            Host                  Path  Backends
            ----                  ----  --------
            kubetest.sairama.com
                                    /                httpd-service:80 (10.1.1.51:80)
                                    /test(/|$)(.*)   httpbin-service:80 (10.1.1.83:80)
          Annotations:            nginx.ingress.kubernetes.io/rewrite-target: /$2
    ```

  * Test
    * httpd

      ```cmd
        curl -v --resolve kubetest.sairama.com:80:localipaddress http://kubetest.sairama.com
      ```

      ```html
        <html><body><h1>It works!</h1></body></html>
      ```

      ```cmd
        curl -v --resolve kubetest.sairama.com:80:localipaddress http://kubetest.sairama.com/test/json
      ```

      ```html
          * Added kubetest.sairama.com:80:localipaddress to DNS cache
          * Hostname kubetest.sairama.com was found in DNS cache
          *   Trying localipaddress:80...
          * Connected to kubetest.sairama.com (localipaddress) port 80
          > GET /test/json HTTP/1.1
          > Host: kubetest.sairama.com
          > User-Agent: curl/8.4.0
          > Accept: */*
          >
          < HTTP/1.1 200 OK
          < Date: Sun, 14 Jan 2024 19:21:22 GMT
          < Content-Type: application/json
          < Content-Length: 429
          < Connection: keep-alive
          < Access-Control-Allow-Origin: *
          < Access-Control-Allow-Credentials: true
          <
          {
            "slideshow": {
              "author": "Yours Truly",
              "date": "date of publication",
              "slides": [
                {
                  "title": "Wake up to WonderWidgets!",
                  "type": "all"
                },
                {
                  "items": [
                    "Why <em>WonderWidgets</em> are great",
                    "Who <em>buys</em> WonderWidgets"
                  ],
                  "title": "Overview",
                  "type": "all"
                }
              ],
              "title": "Sample Slide Show"
            }
          }      
      ```

      ```cmd
        curl -v --resolve kubetest.sairama.com:80:localipaddress http://kubetest.sairama.com/test/status/200
        curl -v --resolve kubetest.sairama.com:80:localipaddress http://kubetest.sairama.com/test/status/400
        curl -v --resolve kubetest.sairama.com:80:localipaddress http://kubetest.sairama.com/test/status/500
        curl -v --resolve kubetest.sairama.com:80:localipaddress http://kubetest.sairama.com/test/anything
      ```

__

##### Dashboard

  ```cmd
    kubectl apply -f https://raw.githubusercontent.com/kubernetes/dashboard/v2.7.0/aio/deploy/recommended.yaml -p {"spec":{"progressDeadlineSeconds":600}}'
  ```

__

##### Using Helm

Lets do the same thing as above , but this time using helm chart.

* Reset docker desktop kubernetes (through settings)
* Install _httpd_

  ```cmd
    **helm install httpd-release oci://registry-1.docker.io/bitnamicharts/apache --set service.type=ClusterIP**
    kubectl port-forward --namespace default svc/httpd-release-apache 8080:80
  ```

  * Test
  
    ```cmd
      curl http://localhost:8080
    ```

    ```html
      <html><body><h1>It works!</h1></body></html>
    ```

* Install _httpbin_

  ```cmd
    helm repo add estahn https://estahn.github.io/charts/
    helm install httpbingo estahn/httpbingo
  ```
  
  * Expose the service through node port

  ```cmd
    kubectl expose deployment httpbingo --type=NodePort --name=httpbingo-test
  ```

  * Test
  
    ```cmd
      curl http://localhost:32199/get
    ```

    ```json
      {
          "args": {},
          "headers": {
              "Accept": [
                  "*/*"
              ],
              "Host": [
                  "localhost:32199"
              ],
              "User-Agent": [
                  "curl/8.4.0"
              ]
          },
          "origin": "dockerip:49676",
          "url": "http://localhost:32199/get"
      }
    ```

* Install Istio
  
  * [install following these instructions](https://istio.io/latest/docs/tasks/traffic-management/ingress/ingress-control/)

  * Enable istio injection in default name space.
  
  ```cmd
    kubectl label namespace default istio-injection=enabled
    kubectl get namespace -L istio-injection
  ```

__

#### Resources

[Kubernetes Networking: Understanding Services and Ingress](https://www.atatus.com/blog/kubernetes-networking-understanding-services-and-ingress/)

[Advanced Guide to Kubernetes Ingress Controllers](https://loft.sh/blog/advanced-guide-to-kubernetes-ingress-controllers/)

[Deploy and Access the Kubernetes Dashboard](https://kubernetes.io/docs/tasks/access-application-cluster/web-ui-dashboard/)

[Istio Install with Helm](https://istio.io/latest/docs/setup/install/helm/)

[Itsio sample - Don't use install from here](https://www.linode.com/docs/guides/how-to-deploy-istio-with-kubernetes/#install-helm-charts)

[Adding Observability AddOns](https://istio.io/latest/docs/tasks/observability/gateways/)

#### Some issues

* ingressClassName: nginx is important in ingress.yaml
* 404 error and no logging means , going to default backend in ingress (when this happens you don't see logs in ingress controller).
