from functools import reduce

Students = [
    {"name": "Анна", "age": 20, "grade": 4.5},
    {"name": "Борис", "age": 22, "grade": 3.8},
    {"name": "Виктор", "age": 19, "grade": 4.2},
    {"name": "Галина", "age": 21, "grade": 4.9},
    {"name": "Дмитрий", "age": 23, "grade": 3.5},
]

# Уровень 1: map
formatted_students = list(map(lambda s: f"Имя: {s['name']}, Оценка: {s['grade']}", Students))

# Уровень 2: filter
filtered_students = list(filter(lambda s: s['grade'] > 4.0, Students))

# Уровень 3: Сравнение подходов для вычисления среднего возраста

# Вариант А: Функциональный подход
ages_mapped = list(map(lambda s: s['age'], filtered_students))
total_age_reduce = reduce(lambda acc, age: acc + age, ages_mapped, 0)
average_age_func = total_age_reduce / len(ages_mapped) if ages_mapped else 0

# Вариант Б: Императивный подход
ages_list = [s['age'] for s in Students if s['grade'] > 4.0]
average_age_imperative = sum(ages_list) / len(ages_list) if ages_list else 0


# Вывод результатов
print("--- Уровень 1: map ---")
print("\n".join(formatted_students))

print("\n--- Уровень 2: filter ---")
for s in filtered_students:
    print(s)

print("\n--- Уровень 3: reduce vs [for ...] ---")
print(f"Средний возраст (через reduce): {average_age_func:.1f} лет")
print(f"Средний возраст (через [for ...]): {average_age_imperative:.1f} лет")
