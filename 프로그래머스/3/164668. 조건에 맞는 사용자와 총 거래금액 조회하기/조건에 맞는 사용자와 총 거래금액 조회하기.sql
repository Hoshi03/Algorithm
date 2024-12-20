-- 코드를 입력하세요
SELECT U.USER_ID, U.NICKNAME, B.TOTAL_SALES
FROM USED_GOODS_USER U
JOIN 
     (SELECT WRITER_ID, STATUS, SUM(PRICE) TOTAL_SALES
       FROM USED_GOODS_BOARD 
       GROUP BY WRITER_ID, STATUS
       HAVING SUM(PRICE) >= 700000 AND STATUS = 'DONE') B
ON U.USER_ID = B.WRITER_ID
ORDER BY 3