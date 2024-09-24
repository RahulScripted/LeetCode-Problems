-- Table: Products

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | product_id  | int     |
-- | low_fats    | enum    |
-- | recyclable  | enum    |
-- +-------------+---------+

-- 1.  product_id is the primary key (column with unique values) for this table.

-- 2.  low_fats is an ENUM (category) of type ('Y', 'N') where 'Y' means this product is low fat and 'N' means it is not.

-- 3.  recyclable is an ENUM (category) of types ('Y', 'N') where 'Y' means this product is recyclable and 'N' means it is not.
 

-- Write a solution to find the ids of products that are both low fat and recyclable. Return the result table in any order.




SELECT P.product_id
FROM Products P
WHERE P.low_fats = 'Y' && P.recyclable ='Y';