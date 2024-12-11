SELECT R.FOOD_TYPE, 
       R.REST_ID, 
       R.REST_NAME, 
       R.FAVORITES
FROM REST_INFO R JOIN (SELECT FOOD_TYPE, MAX(FAVORITES) FAVORITES
                       FROM REST_INFO  
                       GROUP BY FOOD_TYPE) C
ON R.FOOD_TYPE = C.FOOD_TYPE AND R.FAVORITES = C.FAVORITES
ORDER BY 1 DESC





