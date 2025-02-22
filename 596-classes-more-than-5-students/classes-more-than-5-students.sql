# Write your MySQL query statement below
SELECT class
FROM Courses
GROUP BY class
HAVING count(*) > 4
ORDER BY count(*) DESC;
