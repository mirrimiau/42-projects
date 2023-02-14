SELECT `last_name`, `first_name`, CAST(`birthdate` AS DATE) 'birthdate'
FROM `user_card` WHERE `birthdate` LIKE '%1989%'
ORDER BY `last_name` ASC;