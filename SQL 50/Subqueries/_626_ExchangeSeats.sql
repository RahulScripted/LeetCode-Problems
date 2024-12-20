-- Table: Seat

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | student     | varchar |
-- +-------------+---------+

-- 1.  id is the primary key (unique value) column for this table.

-- 2.  Each row of this table indicates the name and the ID of a student.

-- 3.  The ID sequence always starts from 1 and increments continuously.
 

-- Write a solution to swap the seat id of every two consecutive students. If the number of students is odd, the id of the last student is not swapped. Return the result table ordered by id in ascending order.






SELECT id,
    CASE
        WHEN id % 2 = 0 THEN LAG(student) OVER(ORDER BY id)
        ELSE COALESCE(LEAD(student) OVER(ORDER BY id), student)
    END AS student
FROM Seat