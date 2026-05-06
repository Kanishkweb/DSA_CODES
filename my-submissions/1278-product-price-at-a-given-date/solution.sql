# Write your MySQL query statement below
select p.product_id , coalesce((
    select new_price as price
    from Products
    where change_date <= '2019-08-16' and product_id = p.product_id
    order by change_date desc
    limit 1
),10) as price
from Products p
group by p.product_id;
