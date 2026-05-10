# Write your MySQL query statement below
select person_name 
from (
    select person_name , sum(weight) over(order by turn) as totalWeight
    from Queue
) tab1
where totalWeight <= 1000
order by totalWeight desc
limit 1;
