from typing import List
import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r, k = 1, max(piles), 0
        min_k = 2**31 - 1
        while(l <= r):
            k = (l+r)//2
            hr = sum([math.ceil(banana/k) for banana in piles])
            if hr >h:
                l=k+1
            else:
                r = k-1
            if hr <= h:
                min_k = min(k, min_k)
        return min_k
                

def main():
    solution = Solution()

    # Example 1
    piles1 = [3, 6, 7, 11]
    h1 = 8
    output1 = solution.minEatingSpeed(piles1, h1)
    print("Output 1: ", output1)  # Should print 4

    # Example 2
    piles2 = [30, 11, 23, 4, 20]
    h2 = 5
    output2 = solution.minEatingSpeed(piles2, h2)
    print("Output 2: ", output2)  # Should print 30

    # Example 3
    piles3 = [30, 11, 23, 4, 20]
    h3 = 6
    output3 = solution.minEatingSpeed(piles3, h3)
    print("Output 3: ", output3)  # Should print 23

if __name__ == "__main__":
    main()
