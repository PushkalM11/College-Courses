.open "Assignment2.db"

.headers on
.mode list

CREATE VIEW q1 AS
SELECT Name 
FROM artists NATURAL LEFT OUTER JOIN albums;

.output q1_output.csv

SELECT substring(Name, 1, 1) AS Alphabet, count(Name) AS Count
FROM q1
GROUP BY Alphabet;

DROP VIEW q1;