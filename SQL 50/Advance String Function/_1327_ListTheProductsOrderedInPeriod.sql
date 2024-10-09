-- Table: Products

-- +------------------+---------+
-- | Column Name      | Type    |
-- +------------------+---------+
-- | product_id       | int     |
-- | product_name     | varchar |
-- | product_category | varchar |
-- +------------------+---------+

-- 1.  product_id is the primary key (column with unique values) for this table.
 

-- Table: Orders

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | product_id    | int     |
-- | order_date    | date    |
-- | unit          | int     |
-- +---------------+---------+

-- 1.  This table may have duplicate rows.

-- 2.  product_id is a foreign key (reference column) to the Products table.

-- 3.  unit is the number of products ordered in order_date.
 

-- Write a solution to get the names of products that have at least 100 units ordered in February 2020 and their amount. Return the result table in any order.





SELECT P.product_name, SUM(O.unit) AS unit
FROM Products P
INNER JOIN Orders O
ON P.product_id = O.product_id
WHERE DATE_FORMAT(O.order_date, '%Y-%m') = '2020-02'
GROUP BY P.product_id
HAVING SUM(O.unit) >= 100;