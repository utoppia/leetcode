class Solution:
  def rob(self, nums: List[int]) -> int:
    # Dynamic Programming
    dp = [[0,0] for _ in range(len(nums))]
    if not nums:
      return 0
    dp[0][0] = nums[0]
    ans = nums[0]
    for i in range(1, len(nums)):
      dp[i][0] = dp[i-1][1] + nums[i]
      dp[i][1] = max(dp[i-1][0], dp[i-1][1])
      ans = max(dp[i][0], dp[i][1])
    return ans

