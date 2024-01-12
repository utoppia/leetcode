class Solution:
  def letterCombinations(self, digits: str) -> List[str]:

    key = {
      '2': ['a', 'b', 'c'],
      '3': ['d', 'e', 'f'],
      '4': ['g', 'h', 'i'],
      '5': ['j', 'k', 'l'],
      '6': ['m', 'n', 'o'],
      '7': ['p', 'q', 'r', 's'],
      '8': ['t', 'u', 'v'],
      '9': ['w', 'x', 'y', 'z']
    }

    def dfs(digits: str, tmp: str) -> None:
      nonlocal ans, key
      if not digits:
        if tmp:
          ans.append(tmp)
        return

      for ch in key[digits[0]]:
        dfs(digits[1:], tmp + ch)

    ans = []
    dfs(digits, "")

    return ans


