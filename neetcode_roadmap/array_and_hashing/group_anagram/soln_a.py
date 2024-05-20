# from collections import defaultdict

# def group_anagrams_sorting(strs):
#     """Groups anagrams together using sorting.
#     """
#     anagram_map = defaultdict(list)
#     for word in strs:
#         sorted_word = "".join(sorted(word))  # Sort characters as the key
#         anagram_map[sorted_word].append(word)
#     return list(anagram_map.values())

# # Test case
# str_arr = ["bat", "ate", "nat", "tan", "tea", "eat"]
# result = group_anagrams_sorting(str_arr)
# print(result)  # Output: [['bat'], ['ate', 'tea', 'eat'], ['tan', 'nat']]

from collections import Counter, defaultdict

def group_anagrams_counting(strs):
    """Groups anagrams together using character counting.
    """
    anagram_map = defaultdict(list)
    for word in strs:
        count_tuple = tuple(Counter(word).items())  # Count character occurrences
        anagram_map[count_tuple].append(word)
    return list(anagram_map.values())

# Test (same as before)
str_arr = ["bat", "ate", "nat", "tan", "tea", "eat"]
result = group_anagrams_counting(str_arr)
print(result)