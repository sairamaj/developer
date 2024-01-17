* cat /etc/resolv.conf
* dig www.google.com
* [dns linux](https://www.tecmint.com/find-my-dns-server-ip-address-in-linux/)
* minikube **ssh**
* minikube service fleetman-webapp
* minikube addons list
* https://minikube.sigs.k8s.io/docs/handbook/filesync/
* Authorize minikube to Azure registry
  * ```cmd
    To authorize Minikube to access Azure Container Registry, you need to create a Docker registry secret in your Kubernetes cluster. Here are the steps:

    First, you need to install the Azure CLI and login using az login.
    After that, you can get the credentials for your Azure Container Registry using az acr login -n <registry-name> --expose-token. This will give you something like that:
        {
        "accessToken": "averylongtoken",
        "loginServer": "yoursupercoolregistry.azurecr.io"
        }
  ```
* Create a Docker registry secret using the following command:
  * ```cmd
  
    kubectl create secret docker-registry <secret-name> \
    --docker-server=<login-server> \
    --docker-username=<service-principal-ID> \
    --docker-password=<service-principal-password> \
    --docker-email=<email-address>

    ```
 * Replace <secret-name>, <login-server>, <service-principal-ID>, <service-principal-password>, and <email-address> with appropriate values. 
 * Finally, add the secret to your Minikube cluster using kubectl patch serviceaccount default -p '{"imagePullSecrets": [{"name": "<secret-name>"}]}'.
 * [more info](https://stackoverflow.com/questions/47932845/minikube-and-azure-container-registry)