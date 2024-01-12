class Solution:
  def searchRange(self, nums: List[int], target: int) -> List[int]:
    l = bisect.find_left(nums, target)
    if not nums or l >= len(nums) or nums[l] != target:
      return [-1, -1]
    r = bisect.find_right(nums, target)
    return [l, r - 1]
