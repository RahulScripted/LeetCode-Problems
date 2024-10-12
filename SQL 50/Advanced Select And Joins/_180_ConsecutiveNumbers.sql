-- Table: Logs

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | num         | varchar |
-- +-------------+---------+

-- 1.  In SQL, id is the primary key for this table.

-- 2.  id is an auto increment column starting from 1.
 

-- Find all numbers that appear at least three times consecutively. Return the result table in any order.






SELECT DISTINCT l1.Num AS ConsecutiveNums
FROM 
Logs l1,
Logs l2,
Logs l3

WHERE 

l1.id = l2.id-1
AND l2.id = l3.id-1
AND l1.num = l2.num
AND l2.num = l3.num;