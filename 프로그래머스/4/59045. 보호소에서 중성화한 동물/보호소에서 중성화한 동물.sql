-- 코드를 입력하세요
SELECT O.ANIMAL_ID, O.ANIMAL_TYPE, O.NAME
FROM ANIMAL_INS I, ANIMAL_OUTS O
WHERE I.ANIMAL_ID = O.ANIMAL_ID AND O.SEX_UPON_OUTCOME NOT LIKE 'Intact%'
AND I.SEX_UPON_INTAKE  LIKE 'Intact%'
ORDER BY ANIMAL_ID