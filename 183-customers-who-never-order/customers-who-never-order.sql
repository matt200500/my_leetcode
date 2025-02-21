# Write your MySQL query statement below
SELECT t1.name AS Customers
FROM Customers t1
WHERE t1.id NOT IN (SELECT DISTINCT customerID FROM Orders);