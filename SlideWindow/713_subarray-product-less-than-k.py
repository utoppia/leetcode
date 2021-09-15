class Solution:
  def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
    n = len(nums)
    i = j = 0
    if not nums:
      return 0

    cur = nums[i]
    j = 1

    ans = 0

    while i < n: 
      if cur < k:
        ans += (j - i)
      if j == n:
        break
      cur *= nums[j]
      j += 1
      while cur >= k and i <= j:
        cur //= nums[i]
        i += 1

    return ans

