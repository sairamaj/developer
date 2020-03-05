https://<sairamaj>-eval-test.apigee.net/getstarted (https://<organization>-<evaluation>-<environment>.apigee.net/<proxy>)

choco install xsltproc

* pretty with xmllint
    curl https://sairamaj-eval-test.apigee.net/getstarted | xmllint --format -

curl -vs (verbose with suppressing less interest)

* pretty json with python
    curl https://sairamaj-eval-test.apigee.net/getstarted | python -m json.tool

(Note: Make sure choose correct type :request or response)

* Verify API key policy

## Gotchas
?apikey=<>  (case sensitive. apiKey won't work in query parameter)

curl -H "x-apikey: {apikeyhere}" https://sairamaj-eval-test.apigee.net/getstarted

### Concepts
App -> API
App -> API Proxy(Facade)  (Resources)-> API
Attach Policies to Flows (ex: Security)
Resources are children of API Proxy

### Sharing API Proxies with developers
Publishing API
* Creating Products   ( set of API Proxies)
* Registering Developers
* Register Apps


## Registering developer ( to give access to products)
* Custom developer portal
* Apigee Edge API to create form
* Register on behalf of developer in Apigee Edge UI

### Step
* API Proxy (with resources)
* Product (with all api proxies)
* Register App developer
* Register app developer will register their Apps ( Associate Apps with products)

### API
choco install curl (get the latest curl)
curl -I --tlsv1 -k https://api.enterprise.apigee.com/v1/o/sairamaj-eval/apiproducts -u email:pwd

### API tools
Console: https://www.npmjs.com/package/apigeetool#installation
API Explorer: https://apidocs.apigee.com/management/apis/get/organizations/%7Borg_name%7D/apis






