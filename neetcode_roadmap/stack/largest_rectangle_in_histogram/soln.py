from typing import List

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = [] # pair: (index, height)
        max_area = 0
        for i, h in enumerate(heights):
            start = i
            while stack and stack[-1][1] > h:
                index, height = stack.pop()
                max_area = max(max_area, height * (i-index))
                start = index
            stack.append((start, h))
        for i, h  in stack:
            max_area = max(max_area, h*(len(heights)-i))
        return max_area

def main():
    solution = Solution()

    # Example 1
    heights1 = [2, 1, 5, 6, 2, 3]
    output1 = solution.largestRectangleArea(heights1)
    print("Output 1: ", output1)  # Should print 10

    # Example 2
    heights2 = [2, 4]
    output2 = solution.largestRectangleArea(heights2)
    print("Output 2: ", output2)  # Should print 4

    heights3 = [0, 0]
    output3 = solution.largestRectangleArea(heights3)
    print("Output 3: ", output3)

if __name__ == "__main__":
    main()