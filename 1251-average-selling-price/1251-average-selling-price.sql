# Write your MySQL query statement below

select p.product_id , IFNULL(ROUND(SUM(units*price)/SUM(units),2),0) average_price
from Prices as p
LEFT JOIN UnitsSold as u
ON u.product_id = p.product_id
AND u.purchase_date BETWEEN start_date AND end_date
group by product_id
