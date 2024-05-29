from typing import List
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        elem_dict = {}
        for i in range(len(list)):
            if elem_dict.get(nums[i]):
                return nums[i]
            elem_dict[nums[i]] = 1
        