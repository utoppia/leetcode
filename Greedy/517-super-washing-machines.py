class Solution:
  def findMinMoves(self, machines: List[int]) -> int:
    avg = sum(machines)
    if avg % len(machines) != 0:
      return -1

    avg = avg // len(machines)

    ans = 0
    s = 0
    for val in machines:
      val -= avg
      s += val
      ans = max(ans, abs(s), val)

    return ans
