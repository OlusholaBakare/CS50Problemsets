SELECT AVG(rating) FROM movies JOIN ratings ON movies.i
d = ratings.movie_id  WHERE movies.year = 2012;
