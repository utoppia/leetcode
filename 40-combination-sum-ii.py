class Solution:
  def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:

    def dfs(val: int, tmp: List[int], l: int) -> None:
      nonlocal ans, candidates, n, k
      if val == 0:
        ans.append(tmp)
        return 

      for i in range(l, n):
        a = k[i][0]
        for j in range(1, k[i][1] + 1):
          if val - j * a < 0:
            break
          dfs(val - a * j, tmp + [a] * j, i + 1)

    ans = []
    candidates.sort()
    k = list(collections.Counter(candidates).items())
    n = len(k)
    dfs(target, [], 0)
    return ans
