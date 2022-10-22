# Write your MySQL query statement below
select name, sum(amount) as balance
from users join transactions 
on users.account = transactions.account
group by name
having balance > 10000;