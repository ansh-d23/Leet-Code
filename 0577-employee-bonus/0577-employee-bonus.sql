# Write your MySQL query statement below

select e1.name , e2.bonus
from Employee as e1
left join Bonus as e2
on e1.empId = e2.empId
where e2.bonus < 1000 OR e2.bonus IS NULL