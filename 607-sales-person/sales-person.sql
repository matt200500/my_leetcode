# Write your MySQL query statement below
SELECT t1.name
FROM SalesPerson t1
WHERE t1.sales_id NOT IN (
    SELECT t2.sales_id
    FROM Orders t2
    Inner Join Company t3
    ON t3.com_id = t2.com_id
    WHERE t3.name = "RED"
);

