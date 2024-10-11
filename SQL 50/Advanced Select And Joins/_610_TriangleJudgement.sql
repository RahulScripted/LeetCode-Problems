-- Table: Triangle

-- +-------------+------+
-- | Column Name | Type |
-- +-------------+------+
-- | x           | int  |
-- | y           | int  |
-- | z           | int  |
-- +-------------+------+

-- 1.  In SQL, (x, y, z) is the primary key column for this table.

-- 2.  Each row of this table contains the lengths of three line segments.
 

-- Report for every three line segments whether they can form a triangle. Return the result table in any order.





SELECT *, IF(x + y > z AND x + z > y AND y + z > x, 'Yes', 'No') AS triangle
FROM Triangle;