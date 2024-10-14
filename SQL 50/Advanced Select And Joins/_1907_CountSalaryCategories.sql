-- Table: Accounts

-- +-------------+------+
-- | Column Name | Type |
-- +-------------+------+
-- | account_id  | int  |
-- | income      | int  |
-- +-------------+------+

-- 1.  account_id is the primary key (column with unique values) for this table.

-- 2.  Each row contains information about the monthly income for one bank account.
 

-- Write a solution to calculate the number of bank accounts for each salary category. The salary categories are:

-- 1.  "Low Salary": All the salaries strictly less than $20000.

-- 2.  "Average Salary": All the salaries in the inclusive range [$20000, $50000].

-- 3.  "High Salary": All the salaries strictly greater than $50000.


-- The result table must contain all three categories. If there are no accounts in a category, return 0. Return the result table in any order.






SELECT 'Low Salary' AS CATEGORY, COUNT(IF(INCOME < 20000, 1, NULL)) AS accounts_count 
FROM ACCOUNTS
UNION ALL
SELECT 'Average Salary', COUNT(IF(INCOME BETWEEN 20000 AND 50000, 1, NULL)) 
FROM ACCOUNTS
UNION ALL
SELECT 'High Salary', COUNT(IF(INCOME > 50000, 1, NULL)) 
FROM ACCOUNTS