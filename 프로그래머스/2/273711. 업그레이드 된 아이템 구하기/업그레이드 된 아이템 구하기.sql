SELECT I.ITEM_ID, I.ITEM_NAME, I.RARITY
FROM ITEM_TREE IT, ITEM_INFO I
WHERE I.ITEM_ID = IT.ITEM_ID AND IT.PARENT_ITEM_ID IN (SELECT DISTINCT PARENT_ITEM_ID 
                            FROM ITEM_TREE 
                            WHERE PARENT_ITEM_ID IS NOT NULL
                           ) AND IT.PARENT_ITEM_ID IN (SELECT ITEM_ID 
                                                       FROM ITEM_INFO
                                                       WHERE RARITY = 'RARE'
                                                      )
ORDER BY I.ITEM_ID DESC;