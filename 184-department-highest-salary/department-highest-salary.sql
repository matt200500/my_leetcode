# Write your MySQL query statement below
SELECT t2.name AS Department, t1.name AS Employee, t1.salary AS Salary
FROM Employee t1
INNER JOIN Department t2
ON t1.departmentID = t2.id
    WHERE t1.salary = (
        SELECT MAX(t3.salary)
        FROM Employee t3
        WHERE t3.departmentID = t1.departmentID
    );
