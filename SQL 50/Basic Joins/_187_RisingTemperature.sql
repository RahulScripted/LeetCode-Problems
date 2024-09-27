-- Table: Weather

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | recordDate    | date    |
-- | temperature   | int     |
-- +---------------+---------+

-- 1.  id is the column with unique values for this table.
 

-- Write a solution to find all dates' id with higher temperatures compared to its previous dates (yesterday). Return the result table in any order.





SELECT W1.id
FROM Weather W1
INNER JOIN Weather W2
ON W1.recordDate = DATE_ADD(W2.recordDate,INTERVAL 1 DAY)
WHERE W1.temperature > W2.temperature;