SELECT COUNT(`date`) movies
FROM `member_history`
WHERE (`date` > '20061030'
AND `date` < '20070727')
OR (MONTH(`date`) = 12 AND DAY(`date`) = 24);