def is_palindrome(s: str) -> bool:
    if len(s) < 2:
        return True
    if s[0] == s[-1]:
        return is_palindrome(s[1:-1])
    return False


print(is_palindrome("amama"))
