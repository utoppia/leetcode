class Solution:
  def maxSubArray(self, nums: List[int]) -> int:
    n = len(nums)
    if not nums:
      return 0
    ans = nums[0]
    for i in range(1, n):
      nums[i] = max(nums[i], nums[i] + nums[i-1])
      ans = max(ans, nums[i])
    return ans
