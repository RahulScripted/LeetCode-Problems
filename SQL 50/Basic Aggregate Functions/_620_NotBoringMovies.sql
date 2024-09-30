-- Table: Cinema

-- +----------------+----------+
-- | Column Name    | Type     |
-- +----------------+----------+
-- | id             | int      |
-- | movie          | varchar  |
-- | description    | varchar  |
-- | rating         | float    |
-- +----------------+----------+

-- 1.  id is the primary key (column with unique values) for this table.
 

-- Write a solution to report the movies with an odd-numbered ID and a description that is not "boring".Return the result table ordered by rating in descending order.




SELECT id,movie,description,rating 
FROM Cinema
WHERE (id % 2 != 0) AND description != "boring"
ORDER BY rating DESC;