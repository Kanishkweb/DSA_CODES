# Write your MySQL query statement below
select round(count(distinct player_id)/(select count(distinct player_id) from Activity),2) as fraction
from  (select a1.player_id
from Activity a1
inner join (
    select player_id , MIN(event_date) as first_date
    from Activity
    group by player_id
) 
a2 ON a1.player_id = a2.player_id 
and datediff(a1.event_date,a2.first_date) = 1) test;

