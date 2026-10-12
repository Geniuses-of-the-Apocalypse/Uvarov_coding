from sys import setrecursionlimit
import time
def solve(a):
    def with_b(b):
        def with_c(c):
            solutions = []
            def search(x, y):
                if x > 1000:
                    return
                if y > 1000:
                    search(x + 1, -1000)
                    return
                if a * x + b * y == c:
                    solutions.append((x, y))
                search(x, y + 1)
            search(-1000, -1000)
            return solutions
        return with_c
    return with_b


setrecursionlimit(10000000)
if __name__ == "__main__":
    start = time.perf_counter()
    print(solve(5)(3)(11))
    elapsed = time.perf_counter() - start
    print(f"Время выполнения: {elapsed:.6f} секунд")