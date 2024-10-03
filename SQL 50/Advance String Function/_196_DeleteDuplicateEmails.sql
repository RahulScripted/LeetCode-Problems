-- Table: Person

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | email       | varchar |
-- +-------------+---------+

-- 1.  id is the primary key (column with unique values) for this table.

-- 2.  Each row of this table contains an email. The emails will not contain uppercase letters.
 

-- Write a solution to delete all duplicate emails, keeping only one unique email with the smallest id. For SQL users, please note that you are supposed to write a DELETE statement and not a SELECT one.




-- 1st Answer
DELETE p1 
FROM Person p1,Person p2
WHERE p1.Email = p2.Email AND p1.Id > p2.Id

-- 2nd Answer
With Dupli as(
    Select min(id) as MinId
    from Person
    group by email 
)

Delete from Person
where id not in (Select MinId from Dupli);