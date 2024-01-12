class Solution:
  def findMin(self, nums: List[int]) -> int:
    n = len(nums)
    l, r = 0, n - 1
    while l < r:
      mid = (l + r) >> 1
      if nums[mid] < nums[n-1]:
        r  = mid
      else:
        l = mid + 1
    
    return nums[r]
