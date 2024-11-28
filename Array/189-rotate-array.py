class Solution:
  def rotate(self, nums: List[int], k: int) -> None:
    a = nums[len(nums)-k%len(nums):] + nums[:len(nums)-k%len(nums)]
    for i in range(len(nums)):
      nums[i] = a[i]
