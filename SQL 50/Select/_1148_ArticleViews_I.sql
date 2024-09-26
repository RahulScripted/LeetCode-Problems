-- Table: Views

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | article_id    | int     |
-- | author_id     | int     |
-- | viewer_id     | int     |
-- | view_date     | date    |
-- +---------------+---------+

-- 1.  There is no primary key (column with unique values) for this table, the table may have duplicate rows.

-- 2.  Each row of this table indicates that some viewer viewed an article (written by some author) on some date. 

 
-- Write a solution to find all the authors that viewed at least one of their own articles. Return the result table sorted by id in ascending order.




SELECT DISTINCT author_id AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY id;