from functools import partial

# ---------- Уровень 1 ----------
# Каррированная функция filter_by(key)(value)(items)
filter_by = lambda key: lambda value: lambda items: [
    item for item in items if item.get(key) == value
]

products = [
    {"name": "Ноутбук",  "category": "electronics", "price": 1000},
    {"name": "Футболка", "category": "clothes",     "price": 50},
    {"name": "Телефон",  "category": "electronics", "price": 800},
    {"name": "Джинсы",   "category": "clothes",     "price": 100},
]

print(filter_by("category")("electronics")(products))


# ---------- Уровень 2 ----------
# filter_by_category на основе filter_by через partial
filter_by_category = partial(filter_by, "category")

filter_clothes = filter_by_category("clothes")
print(filter_clothes(products))


# ---------- Уровень 3 ----------
# Каррированный greater_than + filter
greater_than = lambda threshold: lambda x: x > threshold

numbers = [1, 5, 12, 3, 20, 8, 15, 2]

over_ten = greater_than(10)
print(list(filter(over_ten, numbers)))

over_five = greater_than(5)
print(list(filter(over_five, numbers)))