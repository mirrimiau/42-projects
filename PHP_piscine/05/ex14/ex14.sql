SELECT `floor_number` 'floor', SUM(`nb_seats`) 'seats'
FROM `cinema`
GROUP BY `floor_number`
ORDER BY SUM(`nb_seats`) DESC;