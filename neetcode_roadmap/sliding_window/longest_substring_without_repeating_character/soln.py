class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_set = set()
        res=0
        l=0
        for r in range(len(s)):
            while s[r] in char_set:
                char_set.remove(s[l])
                l += 1
            char_set.add(s[r])
            res = max(res, len(char_set))
        return res
    
def main():
    solution = Solution()

    # Example 1
    s1 = "abcabcbb"
    output1 = solution.lengthOfLongestSubstring(s1)
    print("Output 1: ", output1)  # Should print 3

    # Example 2
    s2 = "bbbbb"
    output2 = solution.lengthOfLongestSubstring(s2)
    print("Output 2: ", output2)  # Should print 1

    # Example 3
    s3 = "pwwkew"
    output3 = solution.lengthOfLongestSubstring(s3)
    print("Output 3: ", output3)  # Should print 3

    # Example 4
    s4 = " "
    output4 = solution.lengthOfLongestSubstring(s4)
    print("Output 4: ", output4)

    s5 = "anviaj"
    output5 = solution.lengthOfLongestSubstring(s5)
    print("Output 5: ", output5)

    s6 = "jbpnbwwd"
    output6 = solution.lengthOfLongestSubstring(s6)
    print("Output 6: ", output6)


if __name__ == "__main__":
    main()