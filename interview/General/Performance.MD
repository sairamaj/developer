## Performance
* Location of score in a distribution
* Can be thought of deviding the score in to two separate groups.

90% Percentile
```cmd
5,6,7,8,10,11,13
7 numbes
7*90 = 6.3 = 6
6th number is 11 and hence 90% of these numbers is: 11
```
ex:
* John scored at the 59th percentile on an exam means, he scored better than 59% of the people in exam.

* 90% percentile 
  * Gives the confidence of stability of the application
  * Eliminates the unusal spikes from the response
  * Real-world sense
  * Indicates the stability of the application if the ratio of the average response time and 90th percentile is constant (see how close mean(avg) is to this value)

[Perf introduction videos](https://www.youtube.com/watch?v=VzOQB7_Z64E&list=PLjXbLoE5edwfblWEbZgsiyQiZRbVysu45)

![types](../images/PerfTypes.PNG)

* Throughput
  * rate
  * rate of production, transmission, processing
  * Network
    * data transferred from one end to another end per unit of time (KBPS, MBPS)
  * Server
    * Number of requests processed per unit of time (requests per second)
  * Request per unit of time by tool (RPS)

* Standard deviation
  * ![standard deviation](../images/PerfStandardDeviation.PNG)
  * Shows the consistency and stability of the application( lower the value more stability)

 
