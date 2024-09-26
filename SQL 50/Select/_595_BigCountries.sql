-- Table: World

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | name        | varchar |
-- | continent   | varchar |
-- | area        | int     |
-- | population  | int     |
-- | gdp         | bigint  |
-- +-------------+---------+

-- 1.  name is the primary key (column with unique values) for this table.

-- 2.  Each row of this table gives information about the name of a country, the continent to which it belongs, its area, the population, and its GDP value.
 

-- A country is big if:

-- 1.  it has an area of at least three million (i.e., 3000000 km2), or

-- 2.  it has a population of at least twenty-five million (i.e., 25000000).

-- Write a solution to find the name, population, and area of the big countries. Return the result table in any order.




SELECT name,population,area
FROM World 
WHERE area >= 3000000 || population >= 25000000;