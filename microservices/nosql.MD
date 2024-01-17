* NO SQL
  * Embed
    * Good for heavy read
    * Limited number of items
    * There are contained relationships between entities.
    * There are one-to-few relationships between entities.
    * There's embedded data that changes infrequently.
    * There's embedded data that won't grow without bound.
    * There's embedded data that is queried frequently together.
  * Reference
    * Un limited number of items
    * Representing one-to-many relationships.
    * Representing many-to-many relationships.
    * Related data changes frequently.
    * Referenced data could be unbounded
* CosmoDB
  *  A logical partition in Cosmos DB is a combination of the __id__ field and the __partition key__ value. The __partition key__ value determines the __logical partition to which a document belongs__, and the __id__ field __uniquely identifies the document within that partition__.
  * Once the id value is assigned to a document in Cosmos DB, it cannot be changed. If you need to change the id value, you will need to create a new document with the new id value and delete the old document.