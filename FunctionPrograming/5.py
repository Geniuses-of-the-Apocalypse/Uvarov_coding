from functools import reduce

STUDENTS = tuple((
    {"name": "Анна", "age": 20, "grade": 4.5},
    {"name": "Борис", "age": 22, "grade": 3.8},
    {"name": "Виктор", "age": 19, "grade": 4.2},
    {"name": "Галина", "age": 21, "grade": 4.9},
    {"name": "Дмитрий", "age": 23, "grade": 3.5}
))

# Уровень 1: map
FORMATTED_STUDENTS = tuple(map(lambda s: f"Имя: {s['name']}, Оценка: {s['grade']}", STUDENTS))
print(FORMATTED_STUDENTS)

# Уровень 2: filter
FILTERED_STUDENTS = tuple(filter(lambda s: s['grade'] > 4.0, STUDENTS))
print(FILTERED_STUDENTS)

# Уровень 3: reduce
AGES = tuple(map(lambda s: s['age'], FILTERED_STUDENTS))
TOTAL_AGE = reduce(lambda acc, age: acc + age, AGES, 0)
AVERAGE_AGE = TOTAL_AGE / len(AGES) if AGES else 0
print(AVERAGE_AGE)