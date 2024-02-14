from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        output = [0]*len(temperatures)
        temp_stack = []
        for i in range(len(temperatures)):
            while temp_stack != [] and temp_stack[-1][0] < temperatures[i]:
                output[temp_stack[-1][1]] = i - temp_stack[-1][1]
                temp_stack.pop()
            temp_stack.append([temperatures[i], i])
            # print(temp_stack)
        return output

def main():
    solution = Solution()

    # Example 1
    temperatures1 = [73, 74, 75, 71, 69, 72, 76, 73]
    output1 = solution.dailyTemperatures(temperatures1)
    print("Output 1: ", output1)

    # Example 2
    temperatures2 = [30, 40, 50, 60]
    output2 = solution.dailyTemperatures(temperatures2)
    print("Output 2: ", output2)

    # Example 3
    temperatures3 = [30, 60, 90]
    output3 = solution.dailyTemperatures(temperatures3)
    print("Output 3: ", output3)

if __name__ == "__main__":
    main()