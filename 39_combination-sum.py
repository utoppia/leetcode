class Solution:
  def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:

    def dfs(val: int, tmp: List[int], l: int) -> None:
      nonlocal ans, candidates, n
      if val == 0:
        ans.append(tmp)
        return 

      for i in range(l, n):
        a = candidates[i]
        if val - a < 0:
          break
        dfs(val - a, tmp + [a], i)

    ans = []
    candidates.sort()
    n = len(candidates)
    dfs(target, [], 0)
    return ans
