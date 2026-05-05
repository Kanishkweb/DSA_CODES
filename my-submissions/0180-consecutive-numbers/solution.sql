# Write your MySQL query statement below
select distinct p1.num as ConsecutiveNums
from Logs p1
join Logs p2 ON p1.id = p2.id-1
join Logs p3 ON p2.id = p3.id-1
and p1.num = p2.num and p2.num = p3.num;
