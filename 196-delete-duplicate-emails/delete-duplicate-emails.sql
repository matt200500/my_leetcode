DELETE t1
FROM Person t1
Join Person t2
ON t1.email = t2.email
AND t1.id > t2.id;

