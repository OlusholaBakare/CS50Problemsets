SELECT name FROM people WHERE id IN (SELECT person_id F
ROM stars WHERE movie_id = (SELECT id FROM movies WHERE title =
 Toy Story));
