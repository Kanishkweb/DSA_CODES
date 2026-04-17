# Write your MySQL query statement below
select distinct a.num as ConsecutiveNums
from Logs a
join Logs b  ON a.id = b.id - 1
join Logs c ON b.id = c.id -1
where a.num = b.num and b.num = c.num;
