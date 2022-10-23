# Write your MySQL query statement below
select p.product_id, p.product_name
from Sales s
left join Product p
on p.product_id = s.product_id
group by s.product_id
having min(s.sale_date) >= '2019-01-01'
and max(s.sale_date) <= '2019-03-31';

