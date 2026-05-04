# Write your MySQL query statement below
select p2.id
from Weather p1
join Weather p2 ON DATEDIFF(p2.recordDate,p1.recordDate) = 1 && p2.temperature > p1.temperature;
