# Write your MySQL query statement below

select e2.unique_id , e1.name 
from Employees e1 
left outer join EmployeeUNI e2
ON e1.id = e2.id