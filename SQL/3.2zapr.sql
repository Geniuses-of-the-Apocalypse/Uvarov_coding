-- Запрос 1. Фамилии студентов + ID предметов, которые они сдавали
SELECT S.SURNAME AS "Фамилия", EM.subjects_SUBJ_ID AS "ID предмета"
FROM student S
LEFT JOIN exam_marks EM ON S.STUDENT_ID = EM.student_STUDENT_ID
ORDER BY S.SURNAME;

-- Запрос 2. Фамилии студентов + рейтинг университета (включая тех, у кого нет университета)
SELECT S.SURNAME AS "Фамилия", U.RATING AS "Рейтинг"
FROM student S
LEFT JOIN university U ON S.university_UNIV_ID = U.UNIV_ID
ORDER BY S.SURNAME;

-- Запрос 3. Предметы, по которым только хорошие оценки (4 и 5)
SELECT S.SURNAME AS "Фамилия", SUB.SUBJ_NAME AS "Предмет", EM.MARK AS "Оценка"
FROM exam_marks EM
JOIN student S ON EM.student_STUDENT_ID = S.STUDENT_ID
JOIN subjects SUB ON EM.subjects_SUBJ_ID = SUB.SUBJ_ID
WHERE EM.MARK IN (4, 5)
ORDER BY S.SURNAME, SUB.SUBJ_NAME;

-- Запрос 4. Пары студентов из одного города (без повторений)
SELECT S1.SURNAME AS "Студент 1", S2.SURNAME AS "Студент 2", S1.CITY AS "Город"
FROM student S1
JOIN student S2 ON S1.CITY = S2.CITY AND S1.STUDENT_ID < S2.STUDENT_ID
ORDER BY S1.CITY, S1.SURNAME;