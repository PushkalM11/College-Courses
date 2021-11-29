.open "Assignment2.db"

.headers on
.mode list

CREATE TABLE instructor(
inst_name  TEXT,
course_id TEXT);

INSERT INTO instructor (inst_name, course_id) 
VALUES
('Amy','CS1000'),
('Aaron','CS700'),
('Anne','CS400');

CREATE TABLE student(
stu_name  TEXT,
course_id TEXT);

INSERT INTO student (stu_name, course_id) 
VALUES
('Jack','CS800'),
('Jones','CS1000'),
('Jason', 'CS450');

.output q2_output.csv

CREATE VIEW q2_2 AS
SELECT instructor.course_id instructor_course_id, instructor.inst_name, student.stu_name, student.course_id student_course_id
FROM instructor LEFT OUTER JOIN student on instructor.course_id = student.course_id;

CREATE VIEW q2_1 AS
SELECT instructor.course_id instructor_course_id, instructor.inst_name, student.stu_name, student.course_id student_course_id 
FROM student LEFT OUTER JOIN instructor on instructor.course_id = student.course_id;

-- SELECT * FROM q2_1;
-- SELECT * FROM q2_2;

SELECT * 
FROM q2_1 UNION SELECT * FROM q2_2;

DROP TABLE student;
DROP TABLE instructor;

DROP VIEW q2_1;
DROP VIEW q2_2;