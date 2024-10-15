-- Table: Movies

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | movie_id      | int     |
-- | title         | varchar |
-- +---------------+---------+

-- 1.  movie_id is the primary key (column with unique values) for this table.

-- 2.  title is the name of the movie.
 

-- Table: Users

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | user_id       | int     |
-- | name          | varchar |
-- +---------------+---------+

-- 1.  user_id is the primary key (column with unique values) for this table.

-- 2.  The column 'name' has unique values.

-- Table: MovieRating

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | movie_id      | int     |
-- | user_id       | int     |
-- | rating        | int     |
-- | created_at    | date    |
-- +---------------+---------+

-- 1.  (movie_id, user_id) is the primary key (column with unique values) for this table.

-- 2.  This table contains the rating of a movie by a user in their review.

-- 3.  created_at is the user's review date. 
 

-- Write a solution to:

-- 1.  Find the name of the user who has rated the greatest number of movies. In case of a tie, return the lexicographically smaller user name.

-- 2.  Find the movie name with the highest average rating in February 2020. In case of a tie, return the lexicographically smaller movie name.






(SELECT name AS results
FROM MovieRating JOIN Users USING(user_id)
GROUP BY name
ORDER BY COUNT(*) DESC, name
LIMIT 1)

UNION ALL

(SELECT title AS results
FROM MovieRating JOIN Movies USING(movie_id)
WHERE EXTRACT(YEAR_MONTH FROM created_at) = 202002
GROUP BY title
ORDER BY AVG(rating) DESC, title
LIMIT 1);