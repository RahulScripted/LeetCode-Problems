-- Table: Employee

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | name        | varchar |
-- | department  | varchar |
-- | managerId   | int     |
-- +-------------+---------+

-- 1.  id is the primary key (column with unique values) for this table.

-- 2.  Each row of this table indicates the name of an employee, their department, and the id of their manager.

-- 3.  If managerId is null, then the employee does not have a manager.

-- 4.  No employee will be the manager of themself.
 

-- Write a solution to find managers with at least five direct reports. Return the result table in any order.





SELECT name 
FROM Employee 
WHERE id in (
    SELECT managerId 
    FROM Employee 
    GROUP BY managerId 
    HAVING COUNT(managerId)>4
);