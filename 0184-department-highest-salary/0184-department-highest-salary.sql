# Write your MySQL query statement below
select department.name as department, employee.name as employee, employee.salary as salary
from employee inner join department
on employee.departmentId = department.id
where employee.salary = 
    (
        select max(salary) 
        from employee 
        where employee.departmentid = department.id
    )
;