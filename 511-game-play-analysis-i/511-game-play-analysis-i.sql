# Write your MySQL query statement below
select player_id,event_date  as first_login from 
(select player_id,event_date,
row_number() over(partition by player_id order by event_date) as
 ranks from Activity) A
where ranks=1;

