SELECT * FROM student; -- 0
SELECT * FROM marks; -- 0
SELECT COUNT(*) AS "Количество студентов" FROM student; -- 1
SELECT Subject, COUNT(*) AS "Количество оценок" FROM marks GROUP BY Subject; -- 2
SELECT Subject, AVG(Mark) AS "Средний балл" FROM marks GROUP BY Subject; -- 3
SELECT MAX(Mark) AS "Максимальная оценка" FROM marks; -- 4
SELECT COUNT(*) AS "Более 2 А в фамилии" FROM Student WHERE LOWER(Surname) REGEXP 'а.*а'; -- 5