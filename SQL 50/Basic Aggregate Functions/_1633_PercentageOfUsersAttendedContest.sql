-- Table: Users

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | user_id     | int     |
-- | user_name   | varchar |
-- +-------------+---------+

-- 1.  user_id is the primary key (column with unique values) for this table.

-- 2.  Each row of this table contains the name and the id of a user.
 

-- Table: Register

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | contest_id  | int     |
-- | user_id     | int     |
-- +-------------+---------+

-- 1.  (contest_id, user_id) is the primary key (combination of columns with unique values) for this table.

-- 2.  Each row of this table contains the id of a user and the contest they registered into.
 

-- Write a solution to find the percentage of the users registered in each contest rounded to two decimals. Return the result table ordered by percentage in descending order. In case of a tie, order it by contest_id in ascending order.





SELECT contest_id, ROUND(COUNT(DISTINCT Register.user_id)/COUNT(DISTINCT Users.user_id)*100,2) AS percentage 
FROM Users, Register 
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC