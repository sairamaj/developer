Kubectl
  kubectl version

Clutser
   -> POD (atmoic unit - share network, volums, multiple containers)
   -> Deployment creates PODs (PODs has -> * multiple containers)

   -> Node (is either VM or physical machines)
   -> PODs run on node
   -> Node can run multiple PODS
   -> Node will have minimum ( Kubelet(to communicate), Docker/Rt container engine)


Take pictures from kubernetes.io in to power point (with resource link)

troubleshoot
------------
  (If we have only one container we can omit the container name in below commands)
  kubectl get pods
  kubectl describe pods
  kubectl logs <podname>  


Service -> is what clients will talk and service will communicate to pods

kubectl get services
kubectl describe services/<name>
kubectl describe deployment
kubectl get pods -l <lable name>

applying new label
// kubectl label object <name> <newlabel>
kubectl label pod <podname> <newlabel>

kubectl get deployments

// to scale
kubectl scale deployment/<name> --replicas=4

// rolling updates
to see current image

kubectl describe pods (see image field)
// to set new image
kubectl set image deployments<name> <new image version>

kubectl rollout status deployments/<name>
kubectl rollout undo deployments/