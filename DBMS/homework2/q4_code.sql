.open "Assignment2.db"

.headers on
.mode list

CREATE TABLE X (
id_num INTEGER,
id_str TEXT);

INSERT INTO X (id_num, id_str)
VALUES
(1,'A'),
(2,'B'),
(3,'C'),
(4,'D'),
(5,'E');

.output q4_output.csv

SELECT A.id_num || ',' || B.id_num || ',' || C.id_num id_num, A.id_str || ',' || B.id_str || ',' || C.id_str id_str
FROM X A, X B, X C
where A.id_num < B.id_num AND B.id_num < C.id_num;

DROP TABLE X;