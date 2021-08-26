class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:

        def insert(st: List[int], price: int):
            while st and st[-1] >= price:
                st.pop()
            st.append(price)

        def find(st: List[int], price: int):
            l, r = 0, len(st)-1
            ans = 0
            while l <= r:
                mid = (l + r) // 2
                if st[mid] <= price:
                    ans = max(ans, st[mid])
                    l = mid + 1
                else:
                    r = mid - 1
            return ans 
        # monotonic stack
        st = []
        ans = []

        for i in range(len(prices)-1, -1, -1):
            discount = find(st, prices[i])
            ans.append(prices[i] - discount)
            insert(st, prices[i])
        ans.reverse()
        return ans
