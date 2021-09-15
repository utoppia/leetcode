class Solution:
  def maxSubarraySumCircular(self, nums: List[int]) -> int:
    n = len(nums)
    ans = float('-inf')
    cur = 0
    for a in nums:
      cur = a + max(cur, 0)
      ans = max(ans, cur)

    rightsum = [0] * n
    rightsum[-1] = nums[-1]
    for i in range(n-2, -1, -1):
      rightsum[i] = rightsum[i + 1] + nums[i]

    for i in range(n-2, -1, -1):
      rightsum[i] = max(rightsum[i], rightsum[i+1])

    leftsum = 0
    for i in range(n-2):
      leftsum += nums[i]
      ans = max(ans, leftsum + rightsum[i+2])

    return ans
