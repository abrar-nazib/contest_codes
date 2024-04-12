from typing import List 
import collections
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        output = []
        l=r=0
        q = collections.deque() # Queue that will contain indices
        
        while r < len(nums):
            while q and nums[q[-1]] < nums[r]:
                q.pop()
            q.append(r)
            if l > q[0]:
                q.popleft()
            
            if (r+1) >= k:
                output.append(nums[q[0]])
                l+=1
            r+=1
        return output


def main():
    solution = Solution()

    # Example 1
    nums = [1, 3, -1, -3, 5, 3, 6, 7]
    k = 3
    output = solution.maxSlidingWindow(nums, k)
    print("Output: ", output)  # Should print [3, 3, 5, 5, 6, 7]
    
    # Example 2
    nums = [1]
    k = 1
    output = solution.maxSlidingWindow(nums, k)
    print("Output: ", output)  # Should print [1]

if __name__ == "__main__":
    main()