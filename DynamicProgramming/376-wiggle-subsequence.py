class Solution:
  def wiggleMaxLength(self, nums: List[int]) -> int:
    n = len(nums)

    dp = [[0] * n for _ in range(2)]

    dp[0][0] = dp[1][0] = 1
    ans = 1
    for i in range(n):
      for j in range(0, i):
        if nums[j] < nums[i]:
          dp[0][i] = max(dp[0][i], dp[1][j] + 1)
        if nums[j] > nums[i]:
          dp[1][i] = max(dp[1][i], dp[0][j] + 1)

        ans = max(dp[0][i], dp[1][i], ans)

    return ans
