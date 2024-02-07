class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]
        brackect_map={')':'(',']':'[','}':'{'}
        for c in s:
            if c in brackect_map: # If the parenthesis is a closing type
                if stack and stack[-1]==brackect_map[c]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)
        return True if not stack else False

