from heapq import nlargest
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # find the 2 largest value in nums
        a, b = nlargest(2, nums)
        return (a-1) * (b-1)
