from typing import List

class Solution:

    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) -1
        while l <= r:
            mid = (l+r) // 2
            if target == nums[mid]:
                 return mid
             
            # Left Sorted Portion
            if nums[l] <= nums[mid]:
                if target > nums[mid] or target < nums[l]: # Make the right portion traverse
                    l = mid + 1
                else:
                    r = mid - 1
            
            # Right sorted Portion
            else:
                if target < nums[mid] or target > nums[r]:
                    r = mid - 1
                else:
                    l = mid + 1         
                 
        return -1

def test_solution():
    solution = Solution()

    # Test Case 1
    nums1 = [4,5,6,7,0,1,2]
    target1 = 0
    result1 = solution.search(nums1, target1)
    print(result1)  # Expected: 4

    # Test Case 2
    nums2 = [4, 5, 6, 7, 0, 1, 2]
    target2 = 3
    result2 = solution.search(nums2, target2)
    print(result2)  # Expected: -1

    # Test Case 3
    nums3 = [1]
    target3 = 2
    result3 = solution.search(nums3, target3)
    print(result3)  # Expected: -1

    # Additional Test Case
    nums4 = [1, 3]
    target4 = 4
    result4 = solution.search(nums4, target4)
    print(result4)  # Expected: 1

if __name__ == "__main__":
    test_solution()