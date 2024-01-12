CLASS Solution:
  def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
    def next(pos: int) -> int:
      nonlocal nums, n
      cur = nums[pos]
      while pos < n and nums[pos] == cur:
        pos += 1
      return pos

    nums.sort()
    n = len(nums)
    ans = []
    i = 0
    while i < n:
      j = i + 1
      while j < n:
        p = j + 1
        q = n - 1
        while p < q:
          r = nums[i] + nums[j] + nums[p] + nums[q]
          if r == target:
            ans.append([nums[i], nums[j], nums[p], nums[q]])
            p = next(p)
          elif r < target:
            p += 1
          else:
            q -= 1
        j = next(j)
      i = next(i)
    return ans
