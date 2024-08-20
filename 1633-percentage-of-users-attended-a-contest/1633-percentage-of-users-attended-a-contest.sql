SELECT 
    r.contest_id, 
    round(count(user_id) * 100.0 / (select count(user_id) from Users), 2)AS percentage
FROM 
    Register r 
GROUP BY 
    r.contest_id
ORDER BY 
     percentage DESC ,  contest_id