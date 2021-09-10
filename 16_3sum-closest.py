CLASS Solution:
  def threeSumClosest(self, nums: List[int], target: int) -> int:
    nums.sort()
    n = len(nums)
    ans = 0
    cur = 2 ** 31
    for i in range(n):
      p = i + 1
      q = n - 1
      while p < q:
        r = nums[i] + nums[p] + nums[q]
        if r == target:
          return target
        if abs(r - target) < cur:
          ans = r
          cur = abs(r - target)
        if r > target:
          q -= 1
        else:
          p += 1
    return ans
