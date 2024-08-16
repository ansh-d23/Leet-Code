# Write your MySQL query statement below

SELECT v.customer_id , count(v.customer_id) as count_no_trans
FROM Visits as v
LEFT JOIN Transactions as t
ON v.visit_id = t.visit_id
Where t.transaction_id IS NULL
group by v.customer_id
