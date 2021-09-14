class Solution:
  def jump(self, nums: List[int]) -> int:
    n = len(nums)
    ans = 0
    pos = 0
    while pos < n - 1:
      cur = None
      nxt = None
      for j in range(pos, nums[pos] + pos + 1):
        if j >= n:
          continue
        if not cur or j + nums[j] > cur: 
          nxt = j
          cur = j + nums[j]
      ans += 1
      if nums[pos] + pos >= n - 1:
        return ans
      pos = nxt
    return ans

