def is_valid(s):
    """
    Checks if the input string has valid parentheses.

    Args:
        s: A string containing parentheses.

    Returns:
        True if the parentheses are valid, False otherwise.
    """
    stack = []
    mapping = {")": "(", "}": "{", "]": "["}

    for char in s:
        if char in mapping:  # If it's a closing parenthesis
            if not stack or stack.pop() != mapping[char]:
                return False  # Mismatch or no corresponding opening parenthesis
        else:  # If it's an opening parenthesis
            stack.append(char)

    return not stack  # String is valid if the stack is empty at the end

# Test cases
print(is_valid("()"))  # Output: True
print(is_valid("()[]{}"))  # Output: True
print(is_valid("(]"))  # Output: False
print(is_valid("([)]"))  # Output: False
print(is_valid("{[]}"))  # Output: True