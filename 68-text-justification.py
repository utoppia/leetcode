class Solution:
  def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:

    def make_sentence(words: List[str], l: int, maxWidth: int, isLast: bool) -> str:
      if isLast:
        s = " ".join(words)
        s += " " * (maxWidth - len(s))
        return s

      empty = maxWidth - l
      if len(words) == 1:
        return words[0] + " " * empty

      cnt = len(words) - 1
      per = empty // cnt
      extra = empty % cnt
      s = words[0]
      for i in range(cnt):
        s += " " * per
        if i < extra:
          s += " "
        s += words[i + 1]
      return s
    
    cnt = [len(a) for a in words]
    ans = []
    pos = 0
    cur = 0
    n = len(words)

    while pos < n:
      tmp = [words[pos]]
      cur = cnt[pos]
      pos += 1
      real_length = cur
      while pos < n:
        if cur + cnt[pos] + 1 > maxWidth:
          break
        tmp.append(words[pos])
        cur += cnt[pos] + 1
        real_length += cnt[pos]
        pos += 1
      if pos == n:
        ans.append(make_sentence(tmp, real_length, maxWidth, True))
      else:
        ans.append(make_sentence(tmp, real_length, maxWidth, False))
    return ans

