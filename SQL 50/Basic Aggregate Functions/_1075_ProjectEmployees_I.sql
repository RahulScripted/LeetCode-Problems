-- Table: Project

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | project_id  | int     |
-- | employee_id | int     |
-- +-------------+---------+

-- 1.  (project_id, employee_id) is the primary key of this table.

-- 2.  employee_id is a foreign key to Employee table.
 

-- Table: Employee

-- +------------------+---------+
-- | Column Name      | Type    |
-- +------------------+---------+
-- | employee_id      | int     |
-- | name             | varchar |
-- | experience_years | int     |
-- +------------------+---------+

-- 1.  employee_id is the primary key of this table. It's guaranteed that experience_years is not NULL.
 

-- Write an SQL query that reports the average experience years of all the employees for each project, rounded to 2 digits. Return the result table in any order.





SELECT DISTINCT P.project_id,ROUND(AVG(E.experience_years),2) AS average_years 
FROM Project P
JOIN Employee E
ON P.employee_id = E.employee_id
GROUP BY P.project_id;