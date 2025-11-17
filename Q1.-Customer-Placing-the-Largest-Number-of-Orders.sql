
select customer_number
from 
(select customer_number,count(customer_number) as count_customer_number
from Orders
group by customer_number
ORDER BY count_customer_number DESC
LIMIT 1) As t;

