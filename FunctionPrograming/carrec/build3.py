from concurrent.futures import ProcessPoolExecutor

def solve(a):
    def with_b(b):
        def search_y(x, y=-100):
            if y > 100:
                return []

            current = [(x, y)] if a * x + b * y == 11 else []
            return current + search_y(x, y + 1)

        def search_x(x):
            if x > 100:
                return []

            return search_y(x)

        with ProcessPoolExecutor() as pool:
            results = pool.map(search_x, range(-100, 101))
            return [pair for part in results for pair in part]

    return with_b


if __name__ == "__main__":
    print(solve(5)(3))
