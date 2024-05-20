def group_anagrams(str_arr):
    anagram_dict = {}  # Create a dictionary to store anagrams

    for word in str_arr:
        sorted_word = "".join(sorted(word))  # Sort the characters as a key
        if sorted_word in anagram_dict:
            anagram_dict[sorted_word].append(word)  # Append if key exists
        else:
            anagram_dict[sorted_word] = [word]  # Create a new list if key is new

    return list(anagram_dict.values())  # Return a list of grouped anagrams

# Example usage
str_arr = ["bat", "ate", "nat", "tan", "tea", "eat"]
result = group_anagrams(str_arr)
print(result)  # Output: [['bat'], ['nat', 'tan'], ['ate', 'tea', 'eat']]
