-- Table: Activity

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | user_id       | int     |
-- | session_id    | int     |
-- | activity_date | date    |
-- | activity_type | enum    |
-- +---------------+---------+

-- 1.  This table may have duplicate rows.

-- 2.  The activity_type column is an ENUM (category) of type ('open_session', 'end_session', 'scroll_down', 'send_message').

-- 3.  The table shows the user activities for a social media website. 
 
-- Write a solution to find the daily active user count for a period of 30 days ending 2019-07-27 inclusively. A user was active on someday if they made at least one activity on that day. Return the result table in any order.





SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date BETWEEN '2019-06-28' AND  '2019-07-27'
GROUP BY 1;