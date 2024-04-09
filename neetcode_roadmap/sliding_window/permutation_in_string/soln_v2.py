# class Solution:
#     def checkInclusion(self, s1: str, s2: str) -> bool:
#         if len(s1) > len(s2):
#             return False
#         s1Count, s2Count = [0]*26, [0] * 26
#         for i in range(len(s1)):
#             s1Count[ord(s1[i])-ord('a')]+=1
#             s2Count[ord(s2[i])-ord('a')]+=1
#         matches = 0
#         for i in range(26):
#             matches += 1 if s1Count[i] == s2Count[i] else 0
#         l=0
#         for r in range(len(s1), len(s2)):
#             if matches == 26:
#                 return True
#             index = ord(s2[r])-ord('a')
#             if s1Count[r] 
#         return False

# def main():
#     solution = Solution()

#     # Example 1
#     s1 = "ab"
#     s2 = "eidbaooo"
#     output1 = solution.checkInclusion(s1, s2)
#     print("Output 1: ", output1)  # Should print True

#     # Example 2
#     s1 = "ab"
#     s2 = "eidboaoo"
#     output2 = solution.checkInclusion(s1, s2)
#     print("Output 2: ", output2)  # Should print False

#     # Example 3
#     s1 = 'adc'
#     s2 = "dcda"
#     output3 = solution.checkInclusion(s1, s2)
#     print("Output 3: ", output3)

# if __name__ == "__main__":
#     main()