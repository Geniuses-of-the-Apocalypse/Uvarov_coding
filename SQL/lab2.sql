DROP TABLE IF EXISTS Marks;
DROP TABLE IF EXISTS Student;

create table IF NOT EXISTS Student (
	idStudent int(11) not null AUTO_INCREMENT,
    Surname varchar(45) not null,
    Name varchar(20) not null,
    Address varchar(100) default null,
    Tel varchar(11) default null,
    primary key (idStudent)
) engine=InnoDB default charset=utf8;

create table IF NOT EXISTS Marks (
	idMarks int(11) not null auto_increment,
    Subject varchar(45) not null,
    Date_mark date,
    Mark tinyint(4),
    Student_idStudent int(11) not null,
    Primary key (idMarks),
    constraint fk_Marks_Student
		foreign key (Student_idStudent)
        references Student (idStudent)
        on delete cascade
        on update cascade
) engine=InnoDB default charset=utf8;

INSERT INTO Student (Surname, Name, Address, Tel) VALUES
('Иванов', 'Иван', 'ул. Ленина, д. 78', '89161234567'),
('Петров', 'Пётр', 'ул. Мира, д. 5', '89262345678'),
('Сидоров', 'Сидор', 'ул. Гагарина, д. 12', '89373456789'),
('Александрова', 'Анна', 'ул. Ленина, д. 78', '89534567890'),
('Смирнов', 'Алексей', 'ул. Пушкина, д. 3', NULL),
('Кузнецова', 'Мария', 'ул. Ленина, д. 78', '89745678901');

INSERT INTO Marks (Subject, Date_mark, Mark, Student_idStudent) VALUES
('Математика', '2024-01-15', 5, 1),
('Математика', '2024-01-15', 2, 2),
('Математика', '2024-01-16', 4, 3),
('Физика', '2024-01-17', 3, 1),
('Физика', '2024-01-17', 5, 3),
('Информатика', '2024-01-18', 5, 1),
('Информатика', '2024-01-18', 4, 4),
('Математика', '2024-01-19', 3, 5);

SELECT * FROM Student;
SELECT Surname, Tel FROM Student;
SELECT Surname, Tel FROM Student WHERE Tel IS NULL;
SELECT Surname, Subject, Mark FROM Student, Marks WHERE Student.idStudent=Marks.Student_idStudent;
SELECT S.Surname, S.Name, M.Subject, M.Mark FROM Student S Join Marks M ON S.idStudent = M.Student_idStudent WHERE M.Subject='Математика' AND M.Mark=2;
SELECT CONCAT(S.Surname, ' ', Left(S.Name, 1)) AS Result FROM Student S WHERE S.Surname LIKE 'а%' AND S.Surname LIKE '%в%';
SELECT Surname, Tel FROM Student WHERE Tel REGEXP '^[2-57]+$';
SELECT Surname FROM Student WHERE Address LIKE '%д. 78%' OR Address LIKE '%д.78%';
SELECT * FROM Student WHERE Surname IN('Иванов','Петров','Сидоров');
SELECT Surname FROM Student WHERE Surname BETWEEN 'Иванов' AND 'Сидоров' ORDER BY Surname;
SELECT DISTINCT S.Surname FROM Student S JOIN Marks M ON S.idStudent=M.Student_idStudent WHERE M.Subject='Математика' AND M.Mark>=3;
SELECT DISTINCT Mark AS "5-бальная", Mark*20 AS "100-бальная" FROM Marks WHERE Mark is not NULL ORDER BY Mark DESC;
