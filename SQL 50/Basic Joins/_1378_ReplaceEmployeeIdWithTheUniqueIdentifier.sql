-- Table: Employees

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | name          | varchar |
-- +---------------+---------+

-- 1.  id is the primary key (column with unique values) for this table.

-- 2.  Each row of this table contains the id and the name of an employee in a company.
 

-- Table: EmployeeUNI

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | unique_id     | int     |
-- +---------------+---------+

-- 1.  (id, unique_id) is the primary key (combination of columns with unique values) for this table.

-- 2.  Each row of this table contains the id and the corresponding unique id of an employee in the company.
 

-- Write a solution to show the unique ID of each user, If a user does not have a unique ID replace just show null.Return the result table in any order.




SELECT EUNI.unique_id,E.name
FROM EmployeeUNI EUNI
RIGHT JOIN Employees E
ON EUNI.id = E.id;