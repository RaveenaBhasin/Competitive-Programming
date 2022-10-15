# Write your MySQL query statement below
select
    dep.name as department, emp.name as employee, emp.salary as salary
from
    Employee emp
    inner join 
    Department dep
    on emp.departmentId = dep.id
where
    3 > (select count(distinct(emp2.salary))
         from Employee emp2
         where emp2.salary > emp.salary and emp2.departmentId = emp.departmentId)
;
        
       
      