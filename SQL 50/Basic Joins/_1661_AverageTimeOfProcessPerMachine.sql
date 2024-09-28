-- Table: Activity

-- +----------------+---------+
-- | Column Name    | Type    |
-- +----------------+---------+
-- | machine_id     | int     |
-- | process_id     | int     |
-- | activity_type  | enum    |
-- | timestamp      | float   |
-- +----------------+---------+

-- 1.  The table shows the user activities for a factory website.

-- 2.  (machine_id, process_id, activity_type) is the primary key (combination of columns with unique values) of this table.

-- 3.  machine_id is the ID of a machine.

-- 4.  process_id is the ID of a process running on the machine with ID machine_id.

-- 5.  activity_type is an ENUM (category) of type ('start', 'end').

-- 6.  timestamp is a float representing the current time in seconds.

-- 7.  'start' means the machine starts the process at the given timestamp and 'end' means the machine ends the process at the given timestamp.

-- 8.  The 'start' timestamp will always be before the 'end' timestamp for every (machine_id, process_id) pair.

-- 9.  It is guaranteed that each (machine_id, process_id) pair has a 'start' and 'end' timestamp.
 

-- There is a factory website that has several machines each running the same number of processes. Write a solution to find the average time each machine takes to complete a process. The time to complete a process is the 'end' timestamp minus the 'start' timestamp. The average time is calculated by the total time to complete every process on the machine divided by the number of processes that were run. The resulting table should have the machine_id along with the average time as processing_time, which should be rounded to 3 decimal places. Return the result table in any order.





SELECT A1.machine_id,ROUND(AVG(A2.timestamp  - A1.timestamp),3) AS processing_time 
FROM Activity A1
JOIN Activity A2
ON A1.machine_id = A2.machine_id AND A1.process_id  = A2.process_id AND A1.activity_type = "start" AND A2.activity_type = "end"
GROUP BY machine_id;