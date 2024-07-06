# Write your MySQL query statement below

select p.product_name , s.year , s.price 
from Sales s 
Join Product p  using (product_id)