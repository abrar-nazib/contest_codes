from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_counter = {}
        mod_arr = [[] for i in range(len(nums)+1)]
        out_arr=[]
        # print(mod_arr)
        for num in nums:
            freq_counter[num] = 1 + freq_counter.get(num, 0)
        for key, val in freq_counter.items():
            (mod_arr[val]).append(key)
        # print(mod_arr)
        for i in range((len(nums)), 0, -1):
            if mod_arr[i] != []:
                for elem in mod_arr[i]:
                    out_arr.append(elem)
                    if len(out_arr) >= k:
                        return out_arr


# Create an instance of Solution
sol = Solution()

# Test case 1
nums1 = [1,1,1,2,2,3]
k1 = 2
print(sol.topKFrequent(nums1, k1))  # Expected output: [1,2]

# Test case 2
nums2 = [3,0,1,0]
k2 = 1
print(sol.topKFrequent(nums2, k2))  # Expected output: [1]