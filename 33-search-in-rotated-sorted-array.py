class Solution:
  def search(self, nums: List[int], target: int) -> int:

    def find(l:int, r:int) -> int:
      if l > r:
        return -1
      nonlocal nums, target
      mid = (l + r) >> 1
      if nums[mid] == target:
        return mid
  
      if nums[mid] < nums[r]: # sorted
        if nums[mid] <= target and target <= nums[r]:
          return find(mid+1, r)
        else:
          return find(l, mid-1)
      else:
        if nums[l] <= target and nums[mid] >= target: 
          return find(l, mid-1)
        else:
          return find(mid+1, r)

    return find(0, len(nums)-1)
