class Solution:
  def twoSum(self, nums: List[int], target: int) -> List[int]:
    mem = {}
    for i, a in enumerate(nums):
      if target - a in mem:
        return [mem[target - a], i]
      else:
        mem[a] = i

