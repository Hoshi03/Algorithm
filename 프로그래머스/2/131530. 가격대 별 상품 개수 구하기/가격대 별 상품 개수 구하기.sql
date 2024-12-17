SELECT FLOOR(PRICE/10000) * 10000 AS PRICE_GROUP, 
       COUNT(1) AS PRODUCTS
FROM PRODUCT
GROUP BY FLOOR(PRICE/10000)
ORDER BY PRICE_GROUP;