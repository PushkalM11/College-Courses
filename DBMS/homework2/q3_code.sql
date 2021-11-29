.open "Assignment2.db"

.headers on
.mode list

CREATE TABLE clsification(
Length TEXT,
Count INTEGER);

CREATE VIEW q3_1 AS
SELECT count(*) AS Number_of_songs 
FROM tracks t
WHERE t.Milliseconds < 60000;

CREATE VIEW q3_2 AS
SELECT count(*) AS Number_of_songs 
FROM tracks t
WHERE t.Milliseconds > 60000 AND t.Milliseconds < 300000;

CREATE VIEW q3_3 AS
SELECT count(*) AS Number_of_songs 
FROM tracks t
WHERE t.Milliseconds > 300000;

INSERT INTO classification (Length, Count) 
VALUES
('Small', (SELECT * FROM q3_1)),
('Medium', (SELECT * FROM q3_2)),
('Large', (SELECT * FROM q3_3));

.output q3_output.csv

SELECT *
FROM classification;

DROP VIEW q3_1;
DROP VIEW q3_2;
DROP VIEW q3_3;

DROP TABLE classification;