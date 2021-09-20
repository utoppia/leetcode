class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        # monotonic stack
        # dynamic programing

        MOD = 10 ** 9 + 7
        st = [(0,-1)]
        ans = 0
        cur = 0
        for i in range(len(arr)):
            while st and st[-1][0] >= arr[i]:
                val, index = st[-1]
                st.pop()
                cur -= val * (index - st[-1][1])
            cur += arr[i] * (i - st[-1][1])
            st.append((arr[i], i))
            
            ans += cur
        return ans % MOD
