# fab4c6f6327f0b47514871c7509b9a9155141552bb58a56b04949e06c1887cff

ORDERS = (
    {"id": 1, "total": 1500.0, "status": "paid"},
    {"id": 2, "total": 3200.5, "status": "pending"},
    {"id": 3, "total": 780.0,  "status": "paid"},
    {"id": 4, "total": 5400.0, "status": "cancelled"},
    {"id": 5, "total": 2100.0, "status": "paid"},
)

# Уровень 1: map — извлекаем суммы заказов
TOTALS = tuple(map(lambda order: order["total"], ORDERS))
print("Суммы заказов:", TOTALS)

# Уровень 2: класс OptionalBox с методом map
class OptionalBox:
    def __init__(self, value):
        self.value = value

    def map(self, func):
        if self.value is None:
            return OptionalBox(None)
        return OptionalBox(func(self.value))

print("OptionalBox(10).map(*2):", OptionalBox(10).map(lambda x: x * 2).value)
print("OptionalBox(None).map(*2):", OptionalBox(None).map(lambda x: x * 2).value)

# Уровень 3: безопасное извлечение заказа по id через OptionalBox
def find_order_by_id(order_id):
    order = next((o for o in ORDERS if o["id"] == order_id), None)
    return OptionalBox(order)

print("Заказ id=2:", find_order_by_id(2).map(lambda o: o["total"]).value)
print("Заказ id=99:", find_order_by_id(99).map(lambda o: o["total"]).value)
