* backup database
    * backup database dbnamehere to disk='filepath'
* restore database
    * restore database dbnamehere from disk='filepath'

* looping
```sql
    declare @counter int
    declare @name varchar(100)

      set @counter = 1
      while @counter < 12
      begin
        set @counter = @counter + 1
		set @name = 'name_' + convert(varchar(10),@counter)
		select @name      

      end
```

* using multiple where clauses for the same table
[With .. As](https://docs.microsoft.com/en-us/sql/t-sql/queries/with-common-table-expression-transact-sql)

