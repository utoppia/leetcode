class Solution:
  def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:

    def dfs(i: int, tmp: List[int], pos: int) -> None:
      nonlocal arr, n, nums, ans
      if i == 0:
        ans.append(tmp)
        return
      if i % 2 == 0:
        dfs(i // 2, tmp, pos + 1)
      else:
        for j in range(arr[nums[pos]]):
          dfs(i // 2, tmp + [nums[pos]] * (j+1), pos + 1)

    arr = collections.Counter(nums)
    nums = list(arr.keys())
    n = len(nums)
    ans = []

    for i in range(2 ** n):
      dfs(i, [], 0)

    return ans
