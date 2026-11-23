def find_order_by_id(order_id):
    order = next((o for o in ORDERS if o["id"] == order_id), None)
    return OptionalBox(order)
