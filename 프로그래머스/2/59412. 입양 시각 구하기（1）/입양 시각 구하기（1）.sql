SELECT TO_NUMBER(TO_CHAR(DATETIME,'HH24')) HOUR, COUNT(1) COUNT
FROM ANIMAL_OUTS 
WHERE TO_CHAR(DATETIME,'HH24') >= '09' AND TO_CHAR(DATETIME,'HH24') <='20'
GROUP BY TO_NUMBER(TO_CHAR(DATETIME,'HH24'))
ORDER BY TO_NUMBER(TO_CHAR(DATETIME,'HH24'))

