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
