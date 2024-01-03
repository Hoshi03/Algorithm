select DR_NAME, DR_ID, MCDP_CD, DATE_FORMAT(HIRE_YMD,'%Y-%m-%d') HIRE_YMD from doctor where MCDP_CD in ('CS', 'GS')
order by hire_ymd desc, dr_name;