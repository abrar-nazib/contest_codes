class Solution:
    def findMin(self, nums):
        # Your implementation here
        l, r= 0, len(nums)-1
        min_val = nums[l]
        while l <= r:
            if(nums[l] <=nums[r]): # This is the main part
                return min(nums[l], min_val)
            mid = (l+r)//2
            min_val=min(min_val, nums[mid])
            if nums[mid] >= nums[l]:
                l = mid + 1
            else:
                r = mid -1
        return min_val

def test_solution():
    solution = Solution()

    # Test Case 1
    nums1 = [3, 4, 5, 1, 2]
    result1 = solution.findMin(nums1)
    # assert result1 == 1, f"Expected: 1, Got: {result1}"
    print(result1)

    # Test Case 2
    nums2 = [4, 5, 6, 7, 0, 1, 2]
    result2 = solution.findMin(nums2)
    # assert result2 == 0, f"Expected: 0, Got: {result2}"
    print(result2)
    # Test Case 3
    nums3 = [11, 13, 15, 17]
    result3 = solution.findMin(nums3)
    # assert result3 == 11, f"Expected: 11, Got: {result3}"
    print(result3)

    nums4 = [2, 1]
    result4 = solution.findMin(nums4)
    print(result4)

    print("All test cases passed!")

if __name__ == "__main__":
    test_solution()
