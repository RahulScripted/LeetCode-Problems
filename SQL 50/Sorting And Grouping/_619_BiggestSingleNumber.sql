-- Table: MyNumbers

-- +-------------+------+
-- | Column Name | Type |
-- +-------------+------+
-- | num         | int  |
-- +-------------+------+

-- 1.  This table may contain duplicates (In other words, there is no primary key for this table in SQL).

-- 2.   Each row of this table contains an integer.
 

-- A single number is a number that appeared only once in the MyNumbers table. Find the largest single number. If there is no single number, report null.





SELECT MAX(num) as num 
FROM (
    SELECT num 
    FROM MyNumbers 
    GROUP BY num 
    HAVING COUNT(num) = 1
) AS unique_numbers;