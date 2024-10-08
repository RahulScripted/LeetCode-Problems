-- Table: Students

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | student_id    | int     |
-- | student_name  | varchar |
-- +---------------+---------+

-- 1.  student_id is the primary key (column with unique values) for this table.

-- 2.  Each row of this table contains the ID and the name of one student in the school.
 

-- Table: Subjects

-- +--------------+---------+
-- | Column Name  | Type    |
-- +--------------+---------+
-- | subject_name | varchar |
-- +--------------+---------+

-- 1.  subject_name is the primary key (column with unique values) for this table.

-- 2.  Each row of this table contains the name of one subject in the school.
 

-- Table: Examinations

-- +--------------+---------+
-- | Column Name  | Type    |
-- +--------------+---------+
-- | student_id   | int     |
-- | subject_name | varchar |
-- +--------------+---------+

-- 1.  There is no primary key (column with unique values) for this table. It may contain duplicates.

-- 2.  Each student from the Students table takes every course from the Subjects table.

-- 3.  Each row of this table indicates that a student with ID student_id attended the exam of subject_name.
 

-- Write a solution to find the number of times each student attended each exam. Return the result table ordered by student_id and subject_name.





SELECT S.student_id,S.student_name,SUB.subject_name,COUNT(E.student_id) AS attended_exams 
FROM Students S
CROSS JOIN Subjects SUB
LEFT JOIN Examinations E
ON S.student_id = E.student_id AND E.subject_name = SUB.subject_name 
GROUP BY S.student_id, S.student_name, SUB.subject_name
ORDER BY S.student_id,SUB.subject_name;