class Solution:
  def checkInclusion(self, s1: str, s2: str) -> bool:
    patter = collections.Counter(s1)

    origin = collections.Counter(s2[:len(s1)])

    if patter == origin:
      return True

    j = 0
    for i in range(len(s1), len(s2)):
      origin[s2[j]] -= 1
      if origin[s2[j]] == 0:
        del origin[s2[j]]

      if s2[i] in origin:
        origin[s2[i]] += 1
      else:
        origin[s2[i]] = 1

      if origin == patter:
        return True
      j += 1

    return False
