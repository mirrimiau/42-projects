SELECT `title` 'Title', `summary` 'Summary', `prod_year`
FROM `film`
INNER JOIN `genre` ON film.id_genre = genre.id_genre
WHERE `name` = 'erotic'
ORDER BY (`prod_year`) DESC;