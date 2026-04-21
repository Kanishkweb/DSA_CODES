# Write your MySQL query statement below
select reqId as id , count(reqId) as num
from (select requester_id as reqId
from RequestAccepted

union all
 
select accepter_id as reqId
from RequestAccepted) temp
group by reqId
order by num desc
limit 1;

