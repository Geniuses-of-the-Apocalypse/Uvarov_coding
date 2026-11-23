print("OptionalBox(10).map(*2):", OptionalBox(10).map(lambda x: x * 2).value)
print("OptionalBox(None).map(*2):", OptionalBox(None).map(lambda x: x * 2).value)

print("Заказ id=2:", find_order_by_id(2).map(lambda o: o["total"]).value)
print("Заказ id=99:", find_order_by_id(99).map(lambda o: o["total"]).value)
