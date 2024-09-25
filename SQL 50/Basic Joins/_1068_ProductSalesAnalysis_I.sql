-- Table: Sales

-- +-------------+-------+
-- | Column Name | Type  |
-- +-------------+-------+
-- | sale_id     | int   |
-- | product_id  | int   |
-- | year        | int   |
-- | quantity    | int   |
-- | price       | int   |
-- +-------------+-------+

-- 1.  (sale_id, year) is the primary key (combination of columns with unique values) of this table.

-- 2.  product_id is a foreign key (reference column) to Product table.

-- 3.  Each row of this table shows a sale on the product product_id in a certain year.
 

-- Table: Product

-- +--------------+---------+
-- | Column Name  | Type    |
-- +--------------+---------+
-- | product_id   | int     |
-- | product_name | varchar |
-- +--------------+---------+

-- 1.  product_id is the primary key (column with unique values) of this table.

-- 2.  Each row of this table indicates the product name of each product.
 

-- Write a solution to report the product_name, year, and price for each sale_id in the Sales table. Return the resulting table in any order.




SELECT P.product_name,S.year,S.price
FROM Product P
JOIN Sales S
WHERE P.product_id = S.product_id;