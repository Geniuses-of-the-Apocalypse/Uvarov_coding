import csv
from typing import Optional


def parse_csv(data: str) -> list[dict]:
    return list(csv.DictReader(data.splitlines()))


def compute_revenue(rows: list[dict]) -> float:
    return sum(map(lambda x: int(x["quantity"]) * float(x["price"]), rows))


def top_item(rows: list[dict]) -> Optional[dict]:
    if not rows:
        return None

    try:
        return max(
            rows,
            key=lambda x: int(x["quantity"]) * float(x["price"])
        )
    except (ValueError, TypeError, KeyError):
        return None


data = """date,item,quantity,price
2026-09-01,Notebook,12,4.5
2026-09-02,Pen,25,1.2
2026-09-03,Backpack,3,35.0
2026-09-04,Marker,10,2.8
2026-09-05,Folder,8,3.5"""

rows = parse_csv(data)

print("Данные:")
print(rows)

print("\nОбщая выручка:", compute_revenue(rows))

print("\nТовар с максимальной выручкой:")
print(top_item(rows))