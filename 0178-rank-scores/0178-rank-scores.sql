# Write your MySQL query statement below
select
      s1.Score, 
      (select count(distinct(score))
       from Scores s2
       where s1.Score <= s2.Score) 
as 'Rank'
from Scores s1
order by s1.Score desc;