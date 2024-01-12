class Solution:
  def canJump(self, nums: List[int]) -> bool:
    n = len(nums)
    i = 0
    max_n = 0
    while i <= max_n:
      if i + nums[i] > max_n:
        max_n = i + nums[i]
      if max_n >= n - 1:
        return True
      i += 1

    return False
