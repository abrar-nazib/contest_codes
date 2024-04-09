from typing import List
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Make sure the second array is shorter
        if(len(nums1) < len(nums2)):
            nums1, nums2 = nums2, nums1
        
        total_len = len(nums1) + len(nums2)
        half = total_len//2

        l, r = 0, len(nums2) - 1
        while True:
            i = (l+r)//2
            j = half - i -2
            a_left = nums2[i] if i>=0 else float("-infinity")
            a_right = nums2[i+1] if (i+1) <len(nums2) else float("infinity")
            b_left = nums1[j] if j>=0 else float("-infinity")
            b_right = nums1[j+1] if (j+1) < len(nums1) else float("infinity")
            
            if a_left <= b_right and b_left <= a_right:
                if total_len % 2 == 1:
                    return min(a_right, b_right)
                else:
                    return (max(a_left, b_left)+min(a_right, b_right))/2
            if a_left > b_right:
                r = i -1
            else:
                l = i + 1
                
            
            


def main():
    solution = Solution()

    # Example 1
    nums1 = [1, 3]
    nums2 = [2]
    output1 = solution.findMedianSortedArrays(nums1, nums2)
    print("Output 1: ", output1)  # Should print 2.0

    # Example 2
    nums1 = [1, 2]
    nums2 = [3, 4]
    output2 = solution.findMedianSortedArrays(nums1, nums2)
    print("Output 2: ", output2)  # Should print 2.5

    # Example 3
    nums1 =[1, 3, 4, 7]
    nums2 =[2, 5, 6]
    output3 = solution.findMedianSortedArrays(nums1, nums2) 
    print("Output 3: ", output3)
if __name__ == "__main__":
    main()