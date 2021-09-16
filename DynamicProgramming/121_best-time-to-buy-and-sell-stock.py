class Solution:
  def maxProfit(self, prices: List[int]) -> int:
    if not prices:
      return 0

    ans = 0
    cur = prices[0]
    for a in prices[1:]:
      ans = max(ans, a - cur)
      cur = min(cur, a)
    return ans
