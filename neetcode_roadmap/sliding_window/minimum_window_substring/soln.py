import numpy as np
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or len(t) > len(s):
            return ""
        s_dict, t_dict = {}, {}
        for i in t:
            t_dict[i] = t_dict.get(i, 0) + 1
        l, r, match_num = 0, 0, 0
        min_len, min_l, min_r = float('inf'), 0, 0
        while r < len(s):
            if s[r] in t_dict:
                s_dict[s[r]] = s_dict.get(s[r], 0) + 1
                if s_dict[s[r]] == t_dict[s[r]]:
                    match_num += 1
            while match_num == len(t_dict):
                if r - l + 1 < min_len:
                    min_len, min_l, min_r = r - l + 1, l, r
                if s[l] in t_dict:
                    s_dict[s[l]] -= 1
                    if s_dict[s[l]] < t_dict[s[l]]:
                        match_num -= 1
                l += 1
            r += 1
        return "" if min_len == float('inf') else s[min_l:min_r+1]
def main(): 
    solution = Solution()

    # Example 1
    s1 = "ADOBECODEBANC"
    t1 = "ABC"
    output1 = solution.minWindow(s1, t1)
    print("Output 1: ", output1)  # Should print "BANC"

    # Example 2
    s2 = "a"
    t2 = "a"
    output2 = solution.minWindow(s2, t2)
    print("Output 2: ", output2)  # Should print "a"

    # Example 3
    s3 = "a"
    t3 = "aa"
    output3 = solution.minWindow(s3, t3)
    print("Output 3: ", output3)  # Should print ""
    
    # Example 4
    s4 = "abc"
    t4 = "b"
    output4 = solution.minWindow(s4, t4)
    print("Output 4: ", output4)  # Should print "b"

    # Example 5
    s5 = "bbaac"
    t5 = "aba"
    output5 = solution.minWindow(s5, t5)
    print("Output 5: ", output5)  # Should print "baa"

    # Example 6
    s6 = "cabefgecdaecf"
    t6 = "cae"
    output6 = solution.minWindow(s6, t6)
    print("Output 6: ", output6)  # Should print "aec"

if __name__ == "__main__":
    main()