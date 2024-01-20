from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashset = set()
        for elem in nums:
            if elem in hashset:
                return True
            hashset.add(elem);
        return False
        
if __name__ == '__main__':
    nums = [2,3,1]
    s = Solution();
    print(s.containsDuplicate(nums))