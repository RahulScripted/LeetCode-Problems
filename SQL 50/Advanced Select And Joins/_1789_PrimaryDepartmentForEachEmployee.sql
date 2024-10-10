-- Table: Employee

-- +---------------+---------+
-- | Column Name   |  Type   |
-- +---------------+---------+
-- | employee_id   | int     |
-- | department_id | int     |
-- | primary_flag  | varchar |
-- +---------------+---------+

-- 1.  (employee_id, department_id) is the primary key 

-- 2.  (combination of columns with unique values) for this table.

-- 3.  employee_id is the id of the employee.

-- 4.  department_id is the id of the department to which the employee belongs.

-- 5.  primary_flag is an ENUM (category) of type ('Y', 'N'). If the flag is 'Y', the department is the primary department for the employee. If the flag is 'N', the department is not the primary.
 

-- Employees can belong to multiple departments. When the employee joins other departments, they need to decide which department is their primary department. Note that when an employee belongs to only one department, their primary column is 'N'. Write a solution to report all the employees with their primary department. For employees who belong to one department, report their only department. Return the result table in any order.






SELECT employee_id, department_id
FROM Employee
WHERE primary_flag='Y' OR employee_id in(
    SELECT employee_id
    FROM Employee
    Group by employee_id
    having count(employee_id) = 1
);