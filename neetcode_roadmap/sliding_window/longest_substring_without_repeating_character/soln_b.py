def length_of_longest_substring(in_str):
    """Finds the length of the longest substring without repeating characters.

    Args:
        in_str: The input string.

    Returns:
        The length of the longest substring without repeating characters.
    """

    longest_substr_len = 0  
    start = 0  # Start index of the current window
    seen_chars = set()  # Tracks the characters in the current window

    for end, char in enumerate(in_str):
        # If we've seen the character, remove elements until it's no longer in the set
        while char in seen_chars:
            seen_chars.remove(in_str[start])
            start += 1

        seen_chars.add(char)  # Add the character to the set
        longest_substr_len = max(longest_substr_len, end - start + 1)

    return longest_substr_len

# Example usage  
in_str = "aabcdggg"
length = length_of_longest_substring(in_str)
print(length)  # Output: 4 