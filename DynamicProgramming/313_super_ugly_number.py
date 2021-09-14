class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        # simillar with #264
        # dynamic programing
        dp = [0] * n
        m = len(primes)
        point = [0] * m
        
        for i in range(1, n):
            dp[i] = min(dp[point[j]] * primes[j] for j in range(m))
            for j in range(m):
                if dp[i] == dp[point[j]] * primes[j]:
                    point[j] += 1
        return dp[n-1]
