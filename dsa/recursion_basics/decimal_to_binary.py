def findBinary(number) -> str:
    result = number // 2
    remainder = number % 2
    if number // 2 == 0:
        return str(remainder)
    return findBinary(result) + str(remainder)


print(findBinary(12))
