# Write your MySQL query statement below
(select b.name as results
from MovieRating a
left join Users b ON a.user_id = b.user_id
group by b.name
order by count(a.user_id) desc , b.name asc
limit 1)

union all

(select b.title as results
from MovieRating a
left join Movies b ON a.movie_id = b.movie_id
where (a.created_at >= '2020-02-01' and a.created_at <= '2020-02-29')
group by b.title
order by avg(a.rating) desc , b.title
limit 1);
