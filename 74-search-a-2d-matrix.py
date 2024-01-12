class Solution:
  def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
    nums = reduce(add, matrix)
    l = bisect.bisect_left(nums, target)
    if l < len(nums) and nums[l] == target:
      return True
    return False
