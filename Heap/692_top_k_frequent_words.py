from heapq import heappush, heappop
class Word:
  def __init__(self, cnt: int, word: str):
    self.cnt = cnt
    self.word = word

  def __lt__(self, other: 'Word') -> bool:
    if self.cnt < other.cnt:
      return True
    if self.cnt == other.cnt and self.word > other.word:
      return True
    return False

class Solution:
  def topKFrequent(self, words: List[int], k: int) -> List[str]:
    bag = {}
    for word in words:
      if word in bag:
        bag[word] += 1
      else:
        bag[word] = 1

    queue = []
    index = 0

    my_words = [Word(cnt, word) for word, cnt in bag.items()]
    for word in my_words:
      if index < k:
        heappush(queue, word)
        index += 1
      elif word.cnt > queue[0].cnt or word.cnt == queue[0].cnt and word.word < queue[0].word:
        heappop(queue)
        heappush(queue, word)
    
    ans = []
    while queue:
      ans.append(heappop(queue).word)
    ans.reverse()
    return ans


