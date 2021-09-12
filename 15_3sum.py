class Solution:
  def threeSum(self, nums: List[int]) -> List[List[int]]:
    def next(pos: int) -> int:
      nonlocal nums, n
      nxt = pos
      while nxt < n and nums[nxt] == nums[pos]:
        nxt += 1
      return nxt
    
    def prev(pos: int) -> int:
      nonlocal nums, n
      pre = pos
      while pre >= 0 and nums[pre] == nums[pos]:
        pre -= 1
      return pre

    nums.sort()
    ans = []
    n = len(nums)
    i = 0
    while i < n:
      j, k = i+1, n-1
      while j < k:
        cur = nums[i] + nums[j] + nums[k]
        if cur == 0:
          ans.append([nums[i], nums[j], nums[k]])
          j = next(j)
          k = prev(k)
        elif cur > 0:
          k = prev(k)
        else:
          j = next(j)

      i = next(i)
    
    return ans
