# Write your MySQL query statement below
select p.product_name , sum(o.unit) as unit
from Orders o
left join Products p ON o.product_id = p.product_id
and (o.order_date <= '2020-02-29' and o.order_date >= '2020-02-01')
group by product_name
having unit >= 100 and product_name is not null;
