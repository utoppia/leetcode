class Solution:
  def leastInterval(self, tasks: List[str], n: int) -> int:
    freqs = collections.Counter(tasks)

    # maxTaskFreq
    maxTaskFreq = max(freqs.values())

    maxFreqCnt = sum(1 for freq in freqs.values() if freq == maxTaskFreq)
    
    return max(len(tasks), (maxTaskFreq - 1) * (n + 1) + maxFreqCnt)

