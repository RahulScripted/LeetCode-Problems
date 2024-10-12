-- Table: Products

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | product_id    | int     |
-- | new_price     | int     |
-- | change_date   | date    |
-- +---------------+---------+

-- 1.  (product_id, change_date) is the primary key 

-- 2.  (combination of columns with unique values) of this table.

-- 3.  Each row of this table indicates that the price of some product was changed to a new price at some date.
 

-- Write a solution to find the prices of all products on 2019-08-16. Assume the price of all products before any change is 10. Return the result table in any order.





SELECT p.product_id, 
       COALESCE((
           SELECT new_price 
           FROM Products 
           WHERE product_id = p.product_id AND change_date <= '2019-08-16'
           ORDER BY change_date DESC 
           LIMIT 1
       ), 10) AS price
FROM (SELECT DISTINCT product_id FROM Products) p;