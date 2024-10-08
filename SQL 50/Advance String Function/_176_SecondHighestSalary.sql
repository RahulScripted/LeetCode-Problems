-- Table: Employee

-- +-------------+------+
-- | Column Name | Type |
-- +-------------+------+
-- | id          | int  |
-- | salary      | int  |
-- +-------------+------+

-- 1.  id is the primary key (column with unique values) for this table.

-- 2.  Each row of this table contains information about the salary of an employee.
 

-- Write a solution to find the second highest distinct salary from the Employee table. If there is no second highest salary, return null (return None in Pandas).





SELECT(
    SELECT DISTINCT Salary 
    FROM Employee 
    ORDER BY salary DESC 
    LIMIT 1 offset 1
) 
AS SecondHighestSalary;