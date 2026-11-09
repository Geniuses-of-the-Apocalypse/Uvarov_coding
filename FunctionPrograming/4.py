#36264c19b305aebcca4f8dce6c6143321ff60a5e57a55f83a943be72f4d048f8
from types import MappingProxyType
from functools import partial

# ---------- Уровень 1 ----------
FILTER_BY = lambda key: lambda value: lambda items: tuple(
    item for item in items if item.get(key) == value
)

print(FILTER_BY("category")("electronics")
    ([{"name": "Ноутбук",  "category": "electronics", "price": 1000},
    {"name": "Футболка", "category": "clothes",     "price": 50},
    {"name": "Телефон",  "category": "electronics", "price": 800},
    {"name": "Джинсы",   "category": "clothes",     "price": 100}]))

# ---------- Уровень 2 ----------
FILTER_BY_CATEGORY = partial(FILTER_BY, "category")
FILTER_CLOTHES = FILTER_BY_CATEGORY("clothes")

print(FILTER_CLOTHES(
    [{"name": "Ноутбук",  "category": "electronics", "price": 1000},
    {"name": "Футболка", "category": "clothes",     "price": 50},
    {"name": "Телефон",  "category": "electronics", "price": 800},
    {"name": "Джинсы",   "category": "clothes",     "price": 100}]))

# ---------- Уровень 3 ----------
GREATER_THAN = lambda threshold: lambda x: x > threshold

print(tuple(filter(GREATER_THAN(10), [1, 5, 12, 3, 20, 8, 15, 2])))
print(tuple(filter(GREATER_THAN(5), [1, 5, 12, 3, 20, 8, 15, 2])))
