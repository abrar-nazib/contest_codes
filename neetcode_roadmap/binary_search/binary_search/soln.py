from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l=0
        r=len(nums) -1 
        while l <= r:
            mid = (l+r)//2
            if nums[mid] > target:
                r = mid - 1
            elif nums[mid] < target:
                l = mid+1
            else:
                return mid
        return -1                

def main():
    solution = Solution()

    # Example 1
    nums1 = [-1, 0, 3, 5, 9, 12]
    target1 = 9
    output1 = solution.search(nums1, target1)
    print("Output 1: ", output1)  # Should print 4

    # Example 2
    nums2 = [-1, 0, 3, 5, 9, 12]
    target2 = 2
    output2 = solution.search(nums2, target2)
    print("Output 2: ", output2)  # Should print -1

if __name__ == "__main__":
    main()