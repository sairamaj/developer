- command to check the app installed on linux server
    systemsctl status docker
* docker info
* image
  * container (running instance of image)
* giving a name to container
  * docker run --name foo -dt -p 80:80 nginx
* batch
  * docker container stop $(docker container ls -aq)
* restart policy
  * no
  * on-failure
  * unless-stopped
  * always
* docker system df
* auto remove container on exit
  * docker run --rm
* COPY vs ADD
  * COPY local file or directory
  * ADD can use URL and also extract a tar file from the source
    * use curl or wget instead of ADD with url (as ADD will add another layer which increases the size)
* HEALTHCHECK
  * allows us to tell the platform on how to test that our application is healthy.
* COMMIT
  * useful to commit a containers's file changes to settings in to a new image.
* Container creates a writable layer on top.
* docker history to view the layers
* docker image inspect
* Flattening an image to single layer can help reduce the overall size of the image.
* Network
  * Drivers
    * bridge
      * uses a software bridge which allows containers connected to the same bridge network to communicate, while providing isolation from containers which are not connected to that bridge network.
      * brctl show
    * host
      * this driver removes the network isolation between the docker host and the docker contains to use the host's network directly.
    * overlay
    * macvlan
    * none
  * docker network ls
  * docker network inspect bridge


______
* misc
  * change user to root
    * sudo su -
  * netstat -ntlp 
  * apt-get install net-tools
  * apt-get install htop
  * systemctl
  * df -h
  * az ssh vm --resource-group <grouphere> --vm-name <vmhere> --subscription <subhere>