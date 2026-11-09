from functools import reduce

STUDENTS = tuple(
    {"name": "Анна", "age": 20, "grade": 4.5},
    {"name": "Борис", "age": 22, "grade": 3.8},
    {"name": "Виктор", "age": 19, "grade": 4.2},
    {"name": "Галина", "age": 21, "grade": 4.9},
    {"name": "Дмитрий", "age": 23, "grade": 3.5}
)

# Уровень 1: map
formatted_students = tuple(map(lambda s: f"Имя: {s['name']}, Оценка: {s['grade']}", STUDENTS))
print(formatted_students)

# Уровень 2: filter
filtered_students = tuple(filter(lambda s: s['grade'] > 4.0, STUDENTS))
print(filtered_students)

# Уровень 3: reduce
ages = tuple(map(lambda s: s['age'], filtered_students))
total_age = reduce(lambda acc, age: acc + age, ages, 0)
average_age = total_age / len(ages) if ages else 0
print(average_age)