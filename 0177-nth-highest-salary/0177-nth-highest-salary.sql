CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT salary from Employee e1 where N-1=(SELECT COUNT(DISTINCT salary) from Employee e2 WHERE e2.salary > e1.salary)
  );
END