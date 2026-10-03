SELECT DISTINCT S.SUBJ_NAME AS "Предмет"
FROM exam_marks EM
JOIN subjects S ON EM.subjects_SUBJ_ID = S.SUBJ_ID
WHERE EM.MARK > ANY (SELECT MARK FROM exam_marks WHERE subjects_SUBJ_ID = 105);

SELECT S.SUBJ_NAME AS "Предмет", COUNT(*) AS "Количество оценок"
FROM exam_marks EM
JOIN subjects S ON EM.subjects_SUBJ_ID = S.SUBJ_ID
GROUP BY S.SUBJ_NAME
HAVING COUNT(*) < ALL (
    SELECT COUNT(*)
    FROM exam_marks
    GROUP BY subjects_SUBJ_ID
);

SELECT U1.UNIV_NAME AS "Университет 1", U2.UNIV_NAME AS "Университет 2", U1.CITY AS "Город"
FROM university U1
JOIN university U2 ON U1.CITY = U2.CITY AND U1.UNIV_ID < U2.UNIV_ID
ORDER BY U1.CITY, U1.UNIV_NAME;

SELECT S.SURNAME AS "Фамилия", S.NAME AS "Имя", S.STIPEND AS "Стипендия", S.CITY AS "Город"
FROM student S
WHERE S.STIPEND = (
    SELECT MAX(S2.STIPEND)
    FROM student S2
    WHERE S2.CITY = S.CITY
);

SELECT S.SURNAME, S.NAME, S.CITY
FROM student S
WHERE S.CITY NOT IN (SELECT CITY FROM university WHERE CITY IS NOT NULL);
