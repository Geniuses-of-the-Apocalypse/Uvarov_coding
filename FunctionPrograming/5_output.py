# Вывод результатов
print("Уровень 1: map")
print("\n".join(formatted_students))

print("\nУровень 2: filter")
for s in filtered_students:
    print(s)

print("\nУровень 3: reduce")
print(f"Средний возраст (через reduce): {average_age_func:.1f} лет")