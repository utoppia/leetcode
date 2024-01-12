class Solution:
  def twoSum(self, numbers: List[int], target: int) -> List[int]:
    for i in range(len(numbers)):
      j = self.binary_search(numbers, i+1, target-numbers[i])
      if j is not None:
        return [i+1, j+1]

  def binary_search(self, nums: List[int], l: int, target: int) -> int:
    r = len(nums) - 1
    while l <= r:
      mid = (l+r) // 2
      if nums[mid] == target:
        return mid
      if nums[mid] < target:
        l = mid + 1
      else:
        r = mid - 1
    return None
