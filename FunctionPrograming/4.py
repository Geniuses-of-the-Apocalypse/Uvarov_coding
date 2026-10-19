from functools import partial

# ---------- Уровень 1 ----------
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
filter_by_category = partial(filter_by, "category")

filter_clothes = filter_by_category("clothes")
print(filter_clothes(products))


# ---------- Уровень 3 ----------
greater_than = lambda threshold: lambda x: x > threshold

numbers = [1, 5, 12, 3, 20, 8, 15, 2]

print(list(filter(greater_than(10), numbers)))
print(list(filtergreater_than(5), numbers)))