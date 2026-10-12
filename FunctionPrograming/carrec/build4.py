from concurrent.futures import ProcessPoolExecutor
from sys import setrecursionlimit
import time
def search_y(a, b, x, y=-1000):
    if y > 1000:
        return []
    current = [(x, y)] if a * x + b * y == 11 else []
    return current + search_y(a, b, x, y + 1)

def search_x(args):
    a, b, x = args
    return search_y(a, b, x)

def solve(a):
    def with_b(b):
        tasks = ((a, b, x) for x in range(-1000, 1001))
        with ProcessPoolExecutor() as pool:
            results = pool.map(search_x, tasks)
            return [pair for part in results for pair in part]
    return with_b

setrecursionlimit(100000)
if __name__ == "__main__":
    start = time.perf_counter()
    print(solve(5)(3))
    elapsed = time.perf_counter() - start
    print(f"Время выполнения: {elapsed:.6f} секунд")
