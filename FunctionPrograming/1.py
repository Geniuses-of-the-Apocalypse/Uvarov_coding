import csv

def parse_csv(data: str) -> list[dict]:
    return list(csv.DictReader(data.splitlines()))


def compute_revenue(rows: list[dict]) -> float:
    return sum(map(lambda x: float(x["quantity"]) * float(x["price"]), rows))


def top_item(rows):
    return sorted(rows, key=lambda x: float(x['quantity']) * float(x['price']), reverse=True)[0]

data = """date,item,quantity,price
2026-09-01,Notebook,12.0,4.5
2026-09-02,Pen,25.0,1.2
2026-09-03,Backpack,3.0,35.0
2026-09-04,Marker,10.0,2.8
2026-09-05,Folder,8.0,3.5"""

print("Данные:")
print(parse_csv(data))

print("\nОбщая выручка:", compute_revenue(parse_csv(data)))

# topp_item = top_item(parse_csv(data))
# max_rev = float(topp_item['quantity']) * float(topp_item['price'])
# print(f"Максимальная выручка: {max_revenue}")

print("\nТовар с максимальной выручкой:")
print(top_item(parse_csv(data)))
