class Solution:
  def subsets(self, nums: List[int]) -> List[List[int]]:
    n = len(nums)

    ans = []
    for i in range(2 ** n):
      tmp = []
      p = i
      for j in range(n):
        if p & 1:
          tmp.append(nums[j])
        p >>= 1
      ans.append(tmp)

    return ans

