class Solution:
  def deleteAndEarn(self, nums: List[int]) -> int:
    value = {}
    for num in nums:
      if num not in value:
        value[num] = num 
      else:
        value[num] += num

    value_items = sorted(value.items())
    n = len(value)
    dp = [0 for _ in range(max(100, n))]

    for i, (k, v) in enumerate(value_items):
      if k - 1 in value:
        dp[i] = max(v + dp[i-2], dp[i-1])
      else:
        dp[i] = v + dp[i-1]

    return dp[n-1]
