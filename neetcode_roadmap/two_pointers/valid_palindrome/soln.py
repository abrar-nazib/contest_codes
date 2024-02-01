class Solution:
    def isPalindrome(self, s: str) -> bool:
        l = 0
        r = len(s) -1
        while(l < r):
            if not ((s[l].lower()>='a' and s[l].lower()<='z') or (s[l] >= '0' and s[l]<='9')):
                l+=1
                continue
            if not ((s[r].lower()>='a' and s[r].lower() <= 'z') or (s[r] >= '0' and s[r] <= '9')):
                r-=1
                continue
            if not (s[l].lower() == s[r].lower()):
                return False
            l+=1
            r-=1
        return True
 
def main():
    solution = Solution()

    # Example 1
    input1 = "A man, a plan, a canal: Panama"
    output1 = solution.isPalindrome(input1)
    print(output1)  # should print: True

    # Example 2
    input2 = "race a car"
    output2 = solution.isPalindrome(input2)
    print(output2)  # should print: False

    # Example 3
    input3 = " "
    output3 = solution.isPalindrome(input3)
    print(output3)  # should print: True

if __name__ == "__main__":
    main()