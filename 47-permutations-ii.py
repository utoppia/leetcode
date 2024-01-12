class Solution:
  def permuteUnique(self, nums: List[int]) -> List[List[int]]:

    def dfs(dep: int, tmp: List[int]) -> None:
      nonlocal n, ans, k
      if dep == n:
        ans.append(tmp)
        return 

      for v, c in k.items():
        if c > 0:
          k[v] -= 1
          dfs(dep + 1, tmp + [v])
          k[v] += 1

    ans = []
    k = collections.Counter(nums)
    n = len(nums)
    dfs(0, [])
    return ans
