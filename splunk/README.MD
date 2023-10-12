[Splunk Search Tutorial](https://www.learnsplunk.com/splunk-search-tutorial.html)

* Commands
    * Simple search 
    * AND operator
    * OR operator
    * NOT operator
    * TOP command
        ```cmd
             error | top limit=1 error
        ```
    * wild card search(*)
    * __dedup__ removes duplicates values from result.
        ```cmd
            * | dedup uid
        ```
    * __head__ or __tail__
        ```cmd
            error | head limit=10
        ```
    * __stats__
        ```cmd
            error | status count by error
        ```
    * __eval__ to evaluate arbitery expression , perform mathemtaical operations, renaming fields.
    * __chart__ and __timechart__
        ```cmd
            sourcetype="fare" | timechart limit=0 count by airline
        ```
    * __sort__ and __transactions__

* field types
    * host
    * source
    * source_type     
	
|stats count by <fieldname>
* basic search
  * just type the string to search
  * AND, OR and NOT  ( AND is implict)
* Search mode
  * Fast
  * Verbose
  * Smart
* misc
  * unique
  * table
* save reports
  * Schedule reports (Edit-> Schedule)
* add ons / apps
  * apps comes up with pre built dashboards