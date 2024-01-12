class Solution:
  def numberOfArithmeticSlices(self, nums: List[int]) -> int:

    cnt = [0 for i in range(len(nums))]

    ans = 0

    for i in range(2, len(nums)):
      d = nums[i] - nums[i-1]

      if d == nums[i-1] - nums[i-2]:
        cnt[i] += cnt[i-1] + 1
        ans += cnt[i]

    return ans
