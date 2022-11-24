* Relationship
  * One to One
    * User -> User Record (Personal information)
    * Account -> Account record
    * Tenant -> Tenant record
  * One to Many
    * User -> Multiple Accounts
    * User -> Multiple Preferences
  * Many to Many (Require a third table to map - intermediate table)
    * User -> Account
    * Account -> Multiple users (cross accounts, sub users)
    * Product -> Orders 
* Joins
  * LEFT JOIN (left table is main)
  * RIGHT JOIN (right table is main)
  * INNER JOIN (intersection)
* Example
```cmd
Input: 
Visits
+----------+-------------+
| visit_id | customer_id |
+----------+-------------+
| 1        | 23          |
| 2        | 9           |
| 4        | 30          |
| 5        | 54          |
| 6        | 96          |
| 7        | 54          |
| 8        | 54          |
+----------+-------------+
Transactions
+----------------+----------+--------+
| transaction_id | visit_id | amount |
+----------------+----------+--------+
| 2              | 5        | 310    |
| 3              | 5        | 300    |
| 9              | 5        | 200    |
| 12             | 1        | 910    |
| 13             | 2        | 970    |
+----------------+----------+--------+
Output: 
+-------------+----------------+
| customer_id | count_no_trans |
+-------------+----------------+
| 54          | 2              |
| 30          | 1              |
| 96          | 1              |
+-------------+----------------+
```
```sql
SELECT v.customer_id , count(v.customer_id) AS count_no_trans FROM Visits as v 
LEFT JOIN Transactions AS t
ON v.visit_id = t.visit_id
WHERE t.visit_id IS NULL 
GROUP BY v.customer_id;
```

