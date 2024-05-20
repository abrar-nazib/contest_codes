def is_valid_parentheses(s):
    """
    Determines if a string containing parentheses, brackets, and braces is valid.

    Args:
        s: The input string.

    Returns:
        True if the parentheses are valid, False otherwise.
    """

    # Map opening brackets to their corresponding closing brackets
    brackets_map = {
        "(": ")",
        "[": "]",
        "{": "}"
    }

    # Use a stack to keep track of opening brackets
    stack = []

    # Iterate through the characters in the string
    for char in s:
        if char in brackets_map:  # If it's an opening bracket, push it onto the stack
            stack.append(char)
        elif char in brackets_map.values():  # If it's a closing bracket
            # Stack should not be empty, and the top element should match the closing bracket
            if not stack or brackets_map[stack.pop()] != char: 
                return False

    # If the stack is empty at the end, all brackets were balanced
    return not stack  

# Example usage
input_string = "{[()]}()"
if is_valid_parentheses(input_string):
    print("Valid parentheses")
else:
    print("Invalid parentheses")