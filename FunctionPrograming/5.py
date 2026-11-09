from functools import reduce

STUDENTS = tuple(
    {"name": "Анна", "age": 20, "grade": 4.5},
    {"name": "Борис", "age": 22, "grade": 3.8},
    {"name": "Виктор", "age": 19, "grade": 4.2},
    {"name": "Галина", "age": 21, "grade": 4.9},
    {"name": "Дмитрий", "age": 23, "grade": 3.5}
)

# Уровень 1: map
formatted_students = list(map(lambda s: f"Имя: {s['name']}, Оценка: {s['grade']}", Students))

# Уровень 2: filter
filtered_students = list(filter(lambda s: s['grade'] > 4.0, Students))

# Уровень 3: Reduce

ages_mapped = list(map(lambda s: s['age'], filtered_students))
total_age_reduce = reduce(lambda acc, age: acc + age, ages_mapped, 0)
average_age_func = total_age_reduce / len(ages_mapped) if ages_mapped else 0