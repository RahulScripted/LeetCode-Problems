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
 

-- Write a solution to select the product id, year, quantity, and price for the first year of every product sold. Return the resulting table in any order.





SELECT product_id,year AS first_year, quantity, price
FROM Sales
WHERE (product_id, year) IN (SELECT  product_id, min(year) FROM Sales GROUP BY product_id)