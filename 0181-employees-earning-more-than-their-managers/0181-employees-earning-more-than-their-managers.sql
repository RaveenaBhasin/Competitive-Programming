# Write your MySQL query statement below
SELECT name AS Employee FROM Employee e WHERE salary > (SELECT salary FROM Employee m WHERE e.managerId = m.id);