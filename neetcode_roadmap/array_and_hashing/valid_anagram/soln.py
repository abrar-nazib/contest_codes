def is_anagram_sorting(s, ss):
    return sorted(s) == sorted(ss)

from collections import Counter

def is_anagram_counter(s, ss):
    if len(s) != len(ss):
        return False
    return Counter(s) == Counter(ss)

def is_anagram_array(s, ss):
    if len(s) != len(ss):
        return False

    char_counts = [0] * 256
    for char in s:
        char_counts[ord(char)] += 1
    for char in ss:
        char_counts[ord(char)] -= 1
        if char_counts[ord(char)] < 0:
            return False

    return True 

print(is_anagram_sorting("listen", "silent"))  # True
print(is_anagram_counter("tea", "eat"))        # True
print(is_anagram_array("rat", "car"))         # False