-- Table: RequestAccepted

-- +----------------+---------+
-- | Column Name    | Type    |
-- +----------------+---------+
-- | requester_id   | int     |
-- | accepter_id    | int     |
-- | accept_date    | date    |
-- +----------------+---------+

-- 1.  (requester_id, accepter_id) is the primary key

-- 2.  (combination of columns with unique values) for this table.

-- 3.  This table contains the ID of the user who sent the request, the ID of the user who received the request, and the date when the request was accepted.
 

-- Write a solution to find the people who have the most friends and the most friends number. The test cases are generated so that only one person has the most friends.





SELECT id, count(*) AS num 
FROM (
    SELECT requester_id AS id 
    FROM requestAccepted
    UNION ALL
    SELECT accepter_id AS id 
    FROM requestAccepted
) request
GROUP BY id
ORDER BY count(*) DESC
LIMIT 1