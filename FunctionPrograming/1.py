import csv

# Ключи словаря
KEY_QUANTITY = "quantity"
KEY_PRICE = "price"


def _row_revenue(row: dict) -> float:
    return int(row[KEY_QUANTITY]) * float(row[KEY_PRICE])


# Уровень 1: CSV → список словарей
def parse_csv(data: str) -> list[dict]:
    return list(csv.DictReader(data.splitlines()))


# Уровень 2: общая выручка
def compute_revenue(rows: list[dict]) -> float:
    return sum(_row_revenue(row) for row in rows)


# Уровень 3: товар с максимальной выручкой
def top_item(rows: list[dict]) -> dict | None:
    return max(rows, key=_row_revenue, default=None)

# Проверка
# with open("file.csv", newline="") as file:
#     data = file.read()
# 
# rows = parse_csv(data)
# 
# print("Данные:")
# print(rows)
# 
# print("\nОбщая выручка:", compute_revenue(rows))
# 
# print("\nТовар с максимальной выручкой:")
# print(top_item(rows))

