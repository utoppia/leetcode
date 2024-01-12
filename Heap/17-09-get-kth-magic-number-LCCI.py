class Solution:
  def getKthMagicNumber(self, k: int) -> int:
    # heap and set
    queue = [1]
    cur = None
    s = set([1])
    for _ in range(k):
      cur = heappop(queue)
      if 3 * cur not in s:
        s.add(3 * cur)
        heappush(queue, 3 * cur)
      if 5 * cur not in s:
        s.add(5 * cur)
        heappush(queue, 5 * cur)
      if 7 * cur not in s:
        s.add(7 * cur)
        heappush(queue, 7 * cur)
    return cur
