def reverse_str(s: str) -> str:
    if s == "":
        return s

    return reverse_str(s[1:]) + s[0]


print(reverse_str("Mairala"))
