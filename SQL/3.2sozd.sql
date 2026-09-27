CREATE DATABASE IF NOT EXISTS university
  CHARACTER SET utf8 COLLATE utf8_general_ci;

USE university;

-- Университеты
CREATE TABLE university (
  UNIV_ID INT(11) NOT NULL AUTO_INCREMENT,
  UNIV_NAME VARCHAR(45) NOT NULL,
  RATING INT(11) DEFAULT NULL,
  CITY VARCHAR(45) DEFAULT NULL,
  PRIMARY KEY (UNIV_ID)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Преподаватели
CREATE TABLE lecturer (
  LECTURER_ID INT(11) NOT NULL AUTO_INCREMENT,
  SURNAME VARCHAR(45) NOT NULL,
  NAME VARCHAR(20) NOT NULL,
  CITY VARCHAR(45) DEFAULT NULL,
  university_UNIV_ID INT(11) DEFAULT NULL,
  PRIMARY KEY (LECTURER_ID),
  CONSTRAINT fk_lecturer_university
    FOREIGN KEY (university_UNIV_ID) REFERENCES university (UNIV_ID)
    ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Предметы
CREATE TABLE subjects (
  SUBJ_ID INT(11) NOT NULL AUTO_INCREMENT,
  SUBJ_NAME VARCHAR(45) NOT NULL,
  HOUR INT(11) DEFAULT NULL,
  SEMESTER TINYINT(4) DEFAULT NULL,
  PRIMARY KEY (SUBJ_ID)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Студенты
CREATE TABLE student (
  STUDENT_ID INT(11) NOT NULL AUTO_INCREMENT,
  SURNAME VARCHAR(45) NOT NULL,
  NAME VARCHAR(20) NOT NULL,
  STIPEND DECIMAL(6,2) DEFAULT NULL,
  KURS TINYINT(4) DEFAULT NULL,
  CITY VARCHAR(45) DEFAULT NULL,
  BIRTHDAY DATE DEFAULT NULL,
  university_UNIV_ID INT(11) DEFAULT NULL,
  PRIMARY KEY (STUDENT_ID),
  CONSTRAINT fk_student_university
    FOREIGN KEY (university_UNIV_ID) REFERENCES university (UNIV_ID)
    ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Оценки
CREATE TABLE exam_marks (
  EXAM_ID INT(11) NOT NULL AUTO_INCREMENT,
  MARK TINYINT(4) DEFAULT NULL,
  EXAM_DATE DATE DEFAULT NULL,
  student_STUDENT_ID INT(11) NOT NULL,
  subjects_SUBJ_ID INT(11) NOT NULL,
  PRIMARY KEY (EXAM_ID),
  CONSTRAINT fk_exam_student
    FOREIGN KEY (student_STUDENT_ID) REFERENCES student (STUDENT_ID)
    ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT fk_exam_subject
    FOREIGN KEY (subjects_SUBJ_ID) REFERENCES subjects (SUBJ_ID)
    ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Связь преподавателей и предметов
CREATE TABLE subj_lect (
  LECTURER_ID INT(11) NOT NULL,
  subjects_SUBJ_ID INT(11) NOT NULL,
  PRIMARY KEY (LECTURER_ID, subjects_SUBJ_ID),
  CONSTRAINT fk_subjlect_lecturer
    FOREIGN KEY (LECTURER_ID) REFERENCES lecturer (LECTURER_ID)
    ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT fk_subjlect_subject
    FOREIGN KEY (subjects_SUBJ_ID) REFERENCES subjects (SUBJ_ID)
    ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Университеты
INSERT INTO university (UNIV_NAME, RATING, CITY) VALUES
('ВГУ', 350, 'Воронеж'),
('ГУУ', 500, 'Москва'),
('СПбГУ', 450, 'Санкт-Петербург'),
('НГУ', 400, 'Новосибирск');

-- Студенты
INSERT INTO student (SURNAME, NAME, STIPEND, KURS, CITY, BIRTHDAY, university_UNIV_ID) VALUES
('Иванов', 'Иван', 2000, 1, 'Воронеж', '2005-05-15', 1),
('Петров', 'Пётр', 2500, 2, 'Москва', '2004-03-20', 2),
('Сидоров', 'Сидор', 0, 1, 'Воронеж', '2005-07-10', 1),
('Александрова', 'Анна', 3000, 3, 'Санкт-Петербург', '2003-01-25', 3),
('Смирнов', 'Алексей', NULL, 2, 'Казань', '2004-11-05', NULL),
('Кузнецова', 'Мария', 2200, 1, 'Воронеж', '2005-09-30', 1);

-- Предметы
INSERT INTO subjects (SUBJ_NAME, HOUR, SEMESTER) VALUES
('Математика', 120, 1),
('Физика', 100, 2),
('Информатика', 90, 1),
('История', 80, 2);

-- Оценки
INSERT INTO exam_marks (MARK, EXAM_DATE, student_STUDENT_ID, subjects_SUBJ_ID) VALUES
(5, '2024-01-15', 1, 1),
(2, '2024-01-15', 2, 1),
(4, '2024-01-16', 3, 1),
(3, '2024-01-17', 1, 2),
(5, '2024-01-17', 3, 2),
(5, '2024-01-18', 1, 3),
(4, '2024-01-18', 4, 3),
(3, '2024-01-19', 5, 1);

-- Преподаватели
INSERT INTO lecturer (SURNAME, NAME, CITY, university_UNIV_ID) VALUES
('Смирнов', 'Николай', 'Воронеж', 1),
('Козлов', 'Дмитрий', 'Москва', 2),
('Попова', 'Елена', 'Санкт-Петербург', 3);

-- Связь преподавателей и предметов
INSERT INTO subj_lect (LECTURER_ID, subjects_SUBJ_ID) VALUES
(1, 1),
(2, 2),
(3, 3);