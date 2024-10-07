-- Table: Customer

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | customer_id | int     |
-- | product_key | int     |
-- +-------------+---------+

-- 1.  This table may contain duplicates rows. 

-- 2.  customer_id is not NULL.

-- 3.  product_key is a foreign key (reference column) to Product table.
 

-- Table: Product

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | product_key | int     |
-- +-------------+---------+

-- 1.  product_key is the primary key (column with unique values) for this table.
 

-- Write a solution to report the customer ids from the Customer table that bought all the products in the Product table. Return the result table in any order.





SELECT customer_id
FROM Customer
GROUP BY 1
HAVING COUNT(DISTINCT product_key) = (
    SELECT COUNT(*) FROM Product
);