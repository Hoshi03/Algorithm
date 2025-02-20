select 
member_id, member_name, gender, to_char(date_of_birth,'YYYY-MM-dd') DATE_OF_BIRTH
from member_profile 
where 
    to_char(date_of_birth,'MM') like '03' 
    and tlno is not null 
    and gender = 'W'
order by MEMBER_ID;