-- 코드를 입력하세요
SELECT CATEGORY, SUM(SALES)
FROM BOOK B, BOOK_SALES BS
WHERE B.BOOK_ID = BS.BOOK_ID AND TO_CHAR(SALES_DATE,'YYYY-MM') LIKE '2022-01%'
GROUP BY CATEGORY
ORDER BY 1