class Solution:
  def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:

    k = {}
    for a in nums1:
      if a not in k:
        k[a] = 1
      else:
        k[a] += 1

    ans = []
    for a in nums2:
      if a in k and k[a] > 0:
        k[a] -= 1
        ans.append(a)

    return ans

