from collections import defaultdict
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l,r=0,0
        max_len = 0
        freq_dict = defaultdict(int)
        max_freq = 0
        for r in range(len(s)):
            freq_dict[s[r]]+=1
            max_freq = max(max_freq, freq_dict[s[r]])
            window_size = r - l + 1
            if window_size - max_freq <= k:
                max_len = max(window_size, max_len)  
                continue
            freq_dict[s[l]] -=1
            l+=1
        return max_len
            
def main():
    solution = Solution()

    # Example 1
    s1 = "ABAB"
    k1 = 2
    output1 = solution.characterReplacement(s1, k1)
    print("Output 1: ", output1)  # Should print 4

    # Example 2
    s2 = "AABABBA"
    k2 = 1
    output2 = solution.characterReplacement(s2, k2)
    print("Output 2: ", output2)  # Should print 4

if __name__ == "__main__":
    main()