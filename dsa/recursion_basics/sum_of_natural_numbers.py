def sum_till(n: int) -> int:
    if n <= 1:
        return n
    return sum_till(n - 1) + n


print(sum_till(10))
