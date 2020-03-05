developer centric things to know

## [Symantic Version](https://semver.org/)

### single vs double dashes in command line
* single dash is short and double dash full
* single dashes can be combined
* [more](https://serverfault.com/questions/387935/whats-the-difference-betwen-the-single-dash-and-double-dash-flags-on-shell-comm)



# Build
docker image rm imagename:0.0.1 -f
docker build -f .\Dockerfile -t imagename:0.0.1 .
docker run -it imagename:0.0.1

# Push
az acr login --name registryName
docker tag imagename:0.0.1 registryName/imagename:0.0.1
docker push registryName/imageName:0.0.1