SELECT *
FROM CAR_RENTAL_COMPANY_CAR
WHERE FIND_IN_SET('네비게이션', REPLACE(OPTIONS, ' ', '')) > 0
ORDER BY CAR_ID DESC;