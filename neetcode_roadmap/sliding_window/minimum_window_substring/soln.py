import numpy as np
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        s_dict = {}
        t_dict = {}
        matches = []
        for i in range(len(t)):
            t_dict[t[i]] =  t_dict.get(t[i], 0) + 1
        l, r=0,0
        for r in range(len(s)):
            if s[r] in t_dict:
                s_dict[s[r]] = s_dict.get(s[r], 0) + 1
            if s_dict == t_dict:
                matches.append(s[l:r+1])
        for l in range(len(s)):
            if s_dict == t_dict:
                matches.append(s[l:r+1])
            if s[l] in t_dict:
                s_dict[s[l]] -= 1
        if len(matches) == 0:
            return ""
        outputs = []
        for output in matches:
            l_trimmed_output = output
            for i in range(len(output)):
                if output[i] in t_dict:
                    break
                l_trimmed_output = output[i+1:]
            r_trimmed_output = l_trimmed_output
            for i in range(len(l_trimmed_output)-1, -1, -1):        
                if l_trimmed_output[i] in t_dict:
                    break
                r_trimmed_output = l_trimmed_output[:i]
            outputs.append(r_trimmed_output)
        return min(outputs, key=len)

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