# Write your MySQL query statement below
select email as Email
from (select distinct e2.email from Person e1,Person e2 where e1.email=e2.email)as sub

