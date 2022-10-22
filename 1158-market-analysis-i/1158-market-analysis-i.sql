# Write your MySQL query statement below
select 
    u.user_id as buyer_id, 
    join_date, 
    count(order_date) as orders_in_2019
from users as u
left join orders as o
on u.user_id = o.buyer_id
and year(order_date) like '2019%'
group by u.user_id;