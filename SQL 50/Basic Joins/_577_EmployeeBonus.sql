-- Table: Employee

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | empId       | int     |
-- | name        | varchar |
-- | supervisor  | int     |
-- | salary      | int     |
-- +-------------+---------+

-- 1.  empId is the column with unique values for this table.
 

-- Table: Bonus

-- +-------------+------+
-- | Column Name | Type |
-- +-------------+------+
-- | empId       | int  |
-- | bonus       | int  |
-- +-------------+------+

-- 1.  empId is the column of unique values for this table.

-- 2.  empId is a foreign key (reference column) to empId from the Employee table.
 

-- Write a solution to report the name and bonus amount of each employee with a bonus less than 1000. Return the result table in any order.




SELECT E.name,B.bonus
FROM Employee E
LEFT JOIN Bonus B
ON E.empId = B.empId 
WHERE B.bonus < 1000 || B.bonus IS NULL;