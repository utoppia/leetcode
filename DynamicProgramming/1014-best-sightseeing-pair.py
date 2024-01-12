class Solution:
  def maxScoreSightseeingPair(self, values: List[int]) -> int:
    
    # for some j, let
    # cur = max_{ i<j } values[i] + i, so the maximum point
    # end by j is cur + values[j] - j
    ans = 0
    cur = values[0] 
    for j in range(1, len(values)):
      ans = max(ans, cur + values[j] - j)
      cur = max(cur, values[j] + j)

    return ans
