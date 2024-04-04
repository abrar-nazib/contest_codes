from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        i, j=0, 1
        while(j<len(prices)):
            if prices[j]>prices[i]:
                profit = prices[j] - prices[i]
                max_profit = max(profit, max_profit)
            else:
                i = j
            j+=1
        return max_profit

s = Solution()
test_arr_1 = [7,1,5,3,6,4]
test_arr_2 = [7,6,4,3,1]
print(s.maxProfit(test_arr_1))
print(s.maxProfit(test_arr_2))
