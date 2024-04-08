class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s2_freq = [0]*26
        s1_freq = [0]*26
        l=0
        if len(s2) < len(s1):
            return False    
        for c1,c2 in zip(s1, s2):
            s1_freq[ord(c1)-ord('a')] += 1
            s2_freq[ord(c2)-ord('a')] += 1
        if s1_freq == s2_freq:
            return True
        for r in range(len(s1), len(s2)):

            s2_freq[ord(s2[l])-ord('a')]-=1            
            s2_freq[ord(s2[r])-ord('a')]+=1
            if s1_freq == s2_freq:
                return True
            l+=1
        return False

def main():
    solution = Solution()

    # Example 1
    s1 = "ab"
    s2 = "eidbaooo"
    output1 = solution.checkInclusion(s1, s2)
    print("Output 1: ", output1)  # Should print True

    # Example 2
    s1 = "ab"
    s2 = "eidboaoo"
    output2 = solution.checkInclusion(s1, s2)
    print("Output 2: ", output2)  # Should print False

    # Example 3
    s1 = 'adc'
    s2 = "dcda"
    output3 = solution.checkInclusion(s1, s2)
    print("Output 3: ", output3)

if __name__ == "__main__":
    main()