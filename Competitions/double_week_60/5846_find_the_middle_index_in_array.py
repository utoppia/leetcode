class Solution:
  def findMiddleIndex(self, nums: List[int]) -> int:
    s = sum(nums)
    cur = 0
    for i in range(len(nums)):
      if cur == s - cur - nums[i]:
        return i
      cur += nums[i]

    return -1
