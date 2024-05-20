def length_of_longest_substring(in_str):
  """
  Finds the length of the longest substring without repeating characters.

  Args:
      in_str: The input string.

  Returns:
      The length of the longest substring without repeating characters.
  """
  used = set()
  max_length = 0

  i = j = 0
  while i < len(in_str) and j < len(in_str):
    if in_str[j] not in used:
      used.add(in_str[j])
      j += 1
      max_length = max(max_length, j - i)
    else:
      used.remove(in_str[i])
      i += 1

  return max_length

# Test case
in_str = "aabcdggg"
print(length_of_longest_substring(in_str))  # Output: 4