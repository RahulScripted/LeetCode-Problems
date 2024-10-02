-- Table: Patients

-- +--------------+---------+
-- | Column Name  | Type    |
-- +--------------+---------+
-- | patient_id   | int     |
-- | patient_name | varchar |
-- | conditions   | varchar |
-- +--------------+---------+

-- 1.  patient_id is the primary key (column with unique values) for this table.

-- 2.  'conditions' contains 0 or more code separated by spaces. 
 

-- Write a solution to find the patient_id, patient_name, and conditions of the patients who have Type I Diabetes. Type I Diabetes always starts with DIAB1 prefix. Return the result table in any order.





SELECT *
FROM Patients 
WHERE conditions LIKE "DIAB1%" OR conditions LIKE "% DIAB1%";