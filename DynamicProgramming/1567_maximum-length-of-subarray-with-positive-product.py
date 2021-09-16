class Solution:
  def getMaxLen(self, nums: List[int]) -> int:

    dp = [[0, 0] for _ in range(len(nums))]
    dp[0][0] = 1 if nums[0] < 0 else 0
    dp[0][1] = 1 if nums[0] > 0 else 0

    ans = dp[0][1]
    for i in range(1, len(nums)):
      if nums[i] == 0:
        continue

      if nums[i] > 0: # positive
        if dp[i-1][0]:
          dp[i][0] = dp[i-1][0] + 1
        dp[i][1] = dp[i-1][1] + 1
      else: # negative
        dp[i][0] = dp[i-1][1] + 1
        if dp[i-1][0]:
          dp[i][1] = dp[i-1][0] + 1

      ans = max(ans, dp[i][1])

    return ans
