from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        r, c = len(matrix), len(matrix[0])
        top, bottom = 0, r-1
        mid_row=0
        while top<=bottom:
            mid_row = (top+bottom)//2
            if(target < matrix[mid_row][0]):
                bottom = mid_row - 1
            elif(target > matrix[mid_row][-1]):
                top = mid_row + 1
            else:
                break
        if(top <= bottom):
            return False
        l , r = 0, c - 1
        suspect_row = matrix[mid_row]
        while l <= r:
            mid = (l+r)//2
            if(target < suspect_row[mid]):
                r = mid -1
            elif(suspect_row[mid] < target):
                l = mid + 1
            else:
                return True
        return False