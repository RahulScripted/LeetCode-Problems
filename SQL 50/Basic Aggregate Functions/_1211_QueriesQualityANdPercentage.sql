-- Table: Queries

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | query_name  | varchar |
-- | result      | varchar |
-- | position    | int     |
-- | rating      | int     |
-- +-------------+---------+

-- 1.  This table may have duplicate rows.

-- 2.  This table contains information collected from some queries on a database.

-- 3.  The position column has a value from 1 to 500.

-- 4.  The rating column has a value from 1 to 5. Query with rating less than 3 is a poor query.
 

-- We define query quality as: The average of the ratio between query rating and its position. We also define poor query percentage as: The percentage of all queries with rating less than 3. Write a solution to find each query_name, the quality and poor_query_percentage. Both quality and poor_query_percentage should be rounded to 2 decimal places. Return the result table in any order.





SELECT query_name,
       ROUND(AVG(rating / position), 2) AS quality,
       ROUND(AVG(IF(rating < 3, 1, 0)) * 100, 2) AS poor_query_percentage
FROM Queries
WHERE query_name IS NOT NULL
GROUP BY query_name;