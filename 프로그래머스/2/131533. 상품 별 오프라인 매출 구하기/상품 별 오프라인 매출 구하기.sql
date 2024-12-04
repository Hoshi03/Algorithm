-- SELECT PRODUCT_ID, SUM(SALES_AMOUNT) CNT
--                  FROM OFFLINE_SALE
--                  GROUP BY PRODUCT_ID

SELECT PRODUCT_CODE, O.CNT * PRICE SALES
FROM PRODUCT P, (SELECT PRODUCT_ID, SUM(SALES_AMOUNT) CNT
                 FROM OFFLINE_SALE
                 GROUP BY PRODUCT_ID) O
WHERE P.PRODUCT_ID = O.PRODUCT_ID 
ORDER BY SALES DESC, PRODUCT_CODE;

