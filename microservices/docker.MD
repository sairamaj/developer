* how to edit docker desktop kube apiserver.yaml

  ```cmd
        The kube-apiserver.yaml file is a configuration file for the Kubernetes API server. It is used to configure the API server’s behavior, such as authentication, authorization, and admission control 1.

        On Windows, the location of the kube-apiserver.yaml file depends on how you installed Kubernetes. If you installed Kubernetes using Docker Desktop, you can access the file by running the following command in a terminal window 2:

        docker run -it --privileged --pid=host debian nsenter -t 1 -m -u -n -i sh

        This command will allow you to edit the kube-apiserver.yaml file located at /etc/kubernetes/manifests/kube-apiserver.yaml 2. Please note that editing this file can have significant consequences on your Kubernetes cluster, so proceed with caution.

        If you installed Kubernetes using another method, the location of the kube-apiserver.yaml file may be different. Please refer to the documentation for your specific installation method for more information.
  ```

  [edit docker desktop](https://stackoverflow.com/questions/64758012/location-of-kubernetes-config-directory-with-docker-desktop-on-windows)